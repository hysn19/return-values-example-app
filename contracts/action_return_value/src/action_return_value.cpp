#include <eosio/eosio.hpp>

using namespace eosio;

struct action_response
{
  uint16_t id;
  std::pair<int, std::string> status;
};

class [[eosio::contract]] action_return_value : public contract {
  public:
      using contract::contract;

      [[eosio::action]]
      int sum(int valueA, int valueB) {
         return valueA + valueB;
      }

      [[eosio::action]]
      std::string hello() {
          return "hello, EOSIO!";
      }

      [[eosio::action]]
      action_response checkwithrv(name nm) {
         print_f("name : %\n", nm);
         action_response results;
         results.id = 1;
         if (nm == "hello"_n) {
            results.status = {0, "Validation has passed."};
         }
         else {
            results.status = {1, "Input param `name` not equal to `hello`."};
         }
         return results; // the `set_action_return_value` intrinsic is invoked automatically here
      }

  private:
};
