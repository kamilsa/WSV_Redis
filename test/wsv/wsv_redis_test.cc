#include <gtest/gtest.h>
#include <wsv/wsv_redis.h>

TEST(WSV_TEST, GET_TEST){
  wsv::WSVRedis wsvRedis("127.0.0.1", 6379);
}