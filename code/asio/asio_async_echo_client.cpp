/**
 * @brief  异步echo服务器
 * 
 */
#include <cstdlib>
#include <iostream>
#include <memory>
#include <utility>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

class session : public std::enable_shared_from_this<session> {
public:
  session(tcp::socket socket) : socket_(std::move(socket)) {

	}

  void start() { do_write(); }

private:
  void do_read() {
    auto self(shared_from_this());
    socket_.async_read_some(
        boost::asio::buffer(data_, max_length),
        [this, self](boost::system::error_code ec, std::size_t length) {
          if (!ec) {
            std::cout << "receiver data: " <<  std::string(data_, length);
            std::cout << "\n";
            do_write();
          }
        });
  }

  void do_write() {
    std::cout << "Enter message: ";
    std::cin.getline(data_, max_length);
    
    auto self(shared_from_this());
    boost::asio::async_write(
        socket_, boost::asio::buffer(data_,  std::strlen(data_)),
        [this, self](boost::system::error_code ec, std::size_t /*length*/) {
          if (!ec) {
            do_read();
          }
        });
  }

  tcp::socket socket_;
  enum { max_length = 1024 };
  char data_[max_length];
};

class client {
public:
    client(boost::asio::io_service &io_service,  tcp::endpoint &endpoint)
      : socket_(io_service)
      , endpoint_(endpoint)
   {

   }
	void start() {
		do_connet(); 
	}

private:
  void do_connet() {
    socket_.async_connect(endpoint_, [this](boost::system::error_code ec) {
      if (!ec) {
        auto newSession = std::make_shared<session>(std::move(socket_));
        newSession->start();
      }
      else
      {
        std::cout << "connect error." << std::endl;
      }
    });
  }

  tcp::socket socket_;
  tcp::endpoint endpoint_;
};

int main(int argc, char *argv[]) {
  try {
     if (argc != 3) {
      std::cerr << "Usage: main <host> <port>\n";
      return 1;
    }

    boost::asio::io_service io_service;
    tcp::endpoint endpoint(boost::asio::ip::address::from_string(argv[1]), atoi(argv[2]));

    client s(io_service, endpoint);
	s.start();

    io_service.run();
  } catch (std::exception &e) {
    std::cerr << "Exception: " << e.what() << "\n";
  }

  return 0;
}
