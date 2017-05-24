#include <gtest/gtest.h>
#include <wsv/wsv_redis.h>

TEST(WSV_TEST, GET_TEST){
  wsv::WSVRedis wsvRedis("127.0.0.1", 6379);

  wsvRedis.add_account(1, "Ivan");

  std::string ivan = wsvRedis.get_account_by_id(1);

  ASSERT_EQ(ivan, "Ivan");

  uint64_t balance = wsvRedis.get_balance_by_account_id(1);
  ASSERT_EQ(balance, 0);
//
  wsvRedis.add_balance(1, 100);
  balance = wsvRedis.get_balance_by_account_id(1);
  ASSERT_EQ(balance, 100);

  wsvRedis.flush_all();
}