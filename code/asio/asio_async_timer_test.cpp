/**
 * @brief 测试异步定时器
 */
#include <iostream>
#include <boost/asio.hpp>
#include <boost/asio/steady_timer.hpp>
//#include <boost/date_time/posix_time/posix_time.hpp>

void callback(const boost::system::error_code&) {
  std::cout << "Hello, world!" << std::endl;
}

void callback2(const boost::system::error_code&) {
  std::cout << "second call but first run" << std::endl;
}

int main() {
  boost::asio::io_service io;
	
  boost::asio::steady_timer st(io);
	st.expires_from_now(std::chrono::seconds(5));
  st.async_wait(callback);
  
  boost::asio::deadline_timer dt(io, boost::posix_time::seconds(3));
  dt.async_wait(callback2);
 
	std::cout << "first run\n";
  io.run();
  return 0;
}
