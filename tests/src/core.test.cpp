#include <linqpp.hpp>
#include <H2OFastTests.hpp>

using namespace H2OFastTests::Asserter;

struct myException : public std::exception {};

register_scenario(Linqpp_core) {

   add_test("Test v.size() == 100", [=]() {
      auto v = select();
      for (auto&& e : v) {
         std::cout << std::get<0>(e) << std::endl;
      }
      AssertThat(v.size()).isEqualTo(100);
   });

   add_test("throw and catch", [=]() {
      AssertThat([]() {
         throw myException{};
      }).expectException<std::runtime_error>("Not catched !");
   });
}


int main() {

   run_scenario(Linqpp_core);
   print_result(Linqpp_core);

   return 0;
}