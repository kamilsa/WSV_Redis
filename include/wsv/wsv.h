#ifndef WSV_H
#define WSV_H

#include <cpp_redis/redis_client.hpp>
namespace wsv{

class WSV{
 public:

  // adds/removes
  virtual bool add_account(uint64_t account_id, std::string name) = 0;
  virtual bool add_country(uint64_t account_id, std::string country) = 0;
  virtual bool add_balance(uint64_t account_id, std::uint64_t amount) = 0;
  virtual bool remove_balance(uint64_t account_id, std::uint64_t amount) = 0;

  //gets
  virtual std::string get_account_by_id(uint64_t account_id) = 0;
  virtual std::string get_country_by_account_id(uint64_t account_id) = 0;
  virtual uint64_t get_balance_by_account_id(uint64_t account_id) = 0;

};

}
#endif //WSV_H