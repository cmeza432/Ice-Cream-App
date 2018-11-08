#include "test_person.h"
#include "person.h"
#include <iostream>
//#include <sstream>

bool test_person() {
  std::string expected = "";
  bool passed = true; // Optimist!

  //
  // Test constructor
  //

  std::string x_name = "Charlie Chaplin";
  std::string x_id = "tramp";
  std::string x_phone = "555-1212";

  Mice::Person person{x_name, x_id, x_phone};

  // std::ostringstream os;
  // os << person;

  // if (os.str() != "                      Person: Fudge Ripple $1.50") {
  //   std::cerr << "#### Person operator<< fail" << std::endl;
  //   std::cerr << "Expected:                       Person: Fudge Ripple $1.50" << std::endl;
  //   std::cerr << "Actual:   " << os.str() << std::endl;
  // }


  if (person.name() != x_name ||
      person.id() != x_id ||
      person.phone() != x_phone ||
     !person.is_active()) {
    std::cerr << "#### Person constructor fail" << std::endl;
    std::cerr << "Expected: " << x_name << ',' 
                              << x_id << ','
                              << x_phone << ','
                              << "is active" << std::endl;
    std::cerr << "Actual:   " << person.name() << ',' 
                              << person.id() << ','
                              << person.phone() << ','
                              << (person.is_active() ? "is active" : "is not active") << std::endl;
    passed = false;
  }

  //
  // Test set_active and is_active
  //
  person.set_active(false);
  if (person.is_active()) {
    std::cerr << "#### Person: setting inactive failed" << std::endl;
    std::cerr << "Expected: is not active  Actual: " 
              << (person.is_active() ? "is active" : "is not active") << std::endl;
    passed = false;
  }

  person.set_active(true);
  if (!person.is_active()) {
    std::cerr << "#### Person: setting active failed" << std::endl;
    std::cerr << "Expected: is active  Actual: " 
              << (person.is_active() ? "is active" : "is not active") << std::endl;
    passed = false;
  }

  return passed;
}
