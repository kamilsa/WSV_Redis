#include <wsv/wsv_redis.h>

namespace wsv {

WSVRedis::~WSVRedis() {
  client_.disconnect();
}

std::string WSVRedis::get_account_by_id(uint64_t account_id) {
  std::string res;
  client_.hget("account:" + std::to_string(account_id), "name", [&res](cpp_redis::reply& reply) {res = reply.as_string();});
  client_.sync_commit();
  std::cout << res << std::endl;
  return res;
}

std::string WSVRedis::get_country_by_account_id(uint64_t account_id) {
  client_.hget("account:" + std::to_string(account_id), "country");
}

uint64_t WSVRedis::get_balance_by_account_id(uint64_t account_id) {
  client_.hget("account:" + std::to_string(account_id), "balance");
}

}
