#include <wsv/wsv_redis.h>

namespace wsv {

WSVRedis::~WSVRedis() {
  client_.disconnect();
}

bool WSVRedis::add_account(uint64_t account_id, std::string name) {
  std::string string_id = "account:" + std::to_string(account_id);
  client_.hset(string_id, "name", name);
  client_.hset(string_id, "balance", "0");
  client_.sync_commit();
  return true;
}

bool WSVRedis::add_balance(uint64_t account_id, std::uint64_t amount) {
  std::string string_id = "account:" + std::to_string(account_id);
  client_.hincrby(string_id, "balance", amount);
  client_.sync_commit();
  return true;
}

std::string WSVRedis::get_account_by_id(uint64_t account_id) {
  std::string res;
  client_.hget("account:" + std::to_string(account_id), "name", [&res](cpp_redis::reply& reply) {res = reply.as_string();});
  client_.sync_commit();
  return res;
}

uint64_t WSVRedis::get_balance_by_account_id(uint64_t account_id) {
  uint64_t res;
  client_.hget("account:" + std::to_string(account_id), "balance", [&res](cpp_redis::reply& reply) {res = std::stoi(reply.as_string());});
  client_.sync_commit();
  return res;
}

void WSVRedis::flush_all() {
  client_.flushall();
}

}
