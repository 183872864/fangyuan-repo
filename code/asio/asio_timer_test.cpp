/**
 * @brief 测试同步定时器
 */
#include <iostream>
#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

int main() {
  boost::asio::io_service io;
  boost::asio::deadline_timer t(io, boost::posix_time::seconds(5));
  std::cout << t.expires_at() << std::endl;
  t.wait();
  std::cout << "Hello, world!" << std::endl;

  return 0;
}
