/**
 * @brief 异步定时器使用bind
 */
#include <iostream>
#include <boost/asio.hpp>
#include <memory>
#include <vector>
#include <functional>
#include <boost/date_time/posix_time/posix_time.hpp>

void print(const boost::system::error_code & /* e*/,
           std::shared_ptr<boost::asio::deadline_timer> t, int *count) {
  if (*count < 5) {
    std::cout << *count << std::endl;
    ++(*count);

    t->expires_at(t->expires_at() + boost::posix_time::seconds(1));
    t->async_wait(std::bind(print,std::placeholders::_1, t, count));
  }
}

void callback(const boost::system::error_code& e) {
	std::cout << "hello world\n";
}

std::shared_ptr<boost::asio::deadline_timer>
registerPrint(boost::asio::io_service &io, int *count) {
  auto t = std::make_shared<boost::asio::deadline_timer>(
      io, boost::posix_time::seconds(1));
  t->async_wait(std::bind(print, std::placeholders::_1, t, count));
  return t;
}

int main() {
  boost::asio::io_service io;

	std::vector<int> v;
	for(int i = 0;i < 5; ++i) v.push_back(i);
	for (int i = 0; i < 5; ++i) {
		auto t = registerPrint(io, &v[i]);
		std::cout <<"pointer address is: " << t.get() << std::endl;
	}
  io.run();
	for(int i = 0; i < 5; ++i)
  std::cout << "Final count is " << v[i] << std::endl;

  return 0;
}
