#include "test_server.h"
#include "server.h"
#include <iostream>
#include <sstream>

bool test_server() {
  std::string expected = "";
  bool passed = true; // Optimist!

  //
  // Test constructor
  //

  std::string x_name = "Charlie Chaplin";
  std::string x_id = "tramp";
  std::string x_phone = "555-1212";
  double x_salary = 15;

  Mice::Server server{x_name, x_id, x_phone, x_salary};

  // std::ostringstream os;
  // os << server;

  // if (os.str() != "                      Server: Fudge Ripple $1.50") {
  //   std::cerr << "#### Server operator<< fail" << std::endl;
  //   std::cerr << "Expected:                       Server: Fudge Ripple $1.50" << std::endl;
  //   std::cerr << "Actual:   " << os.str() << std::endl;
  // }


  if (server.name() != x_name ||
      server.id() != x_id ||
      server.phone() != x_phone ||
      server.salary() != x_salary ||
      server.num_orders() != 0 ||
     !server.is_active()) {
    std::cerr << "#### Server constructor fail" << std::endl;
    std::cerr << "Expected: " << x_name << ',' 
                              << x_id << ','
                              << x_phone << ','
                              << x_salary << ','
                              << '0' << ','
                              << "is active" << std::endl;
    std::cerr << "Actual:   " << server.name() << ',' 
                              << server.id() << ','
                              << server.phone() << ','
                              << server.salary() << ','
                              << server.num_orders() << ','
                              << (server.is_active() ? "is active" : "is not active") << std::endl;
    passed = false;
  }

  return passed;
}
