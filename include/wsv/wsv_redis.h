//
// Created by kamilsa on 23.05.17.
//

#ifndef WSV_REDIS_H
#define WSV_REDIS_H

#include <wsv/wsv.h>

namespace wsv{

class WSVRedis : public WSV{
 public:
  WSVRedis(std::string &host, size_t port) : host_(host), port_(port){
    client_.connect(host_, port_);
  }
  ~WSVRedis();

  std::string get_account_by_id(uint64_t account_id);
  std::string get_country_by_account_id(uint64_t account_id);
  uint64_t get_balance_by_account_id(uint64_t account_id);

 private:
  cpp_redis::redis_client client_;
  std::string host_;
  size_t port_;
};

}

#endif //WSV_REDIS_H
