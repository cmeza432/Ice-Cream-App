#include "mainwin.h"
#include <exception>
#include <stdexcept>
#include <iostream>
#include <iomanip>
#include <sstream>

/////////////////////
// T E M P L A T E //
/////////////////////
template <typename T>
std::string to_string_precision(const T a_value)
{
  std::ostringstream out;
  out << std::setprecision(6) << a_value;
  return out.str();
}

void Mainwin::on_pay_for_order_click() {
    int order = select_order(Mice::Order_state::Filled);
    if (order < 0) return;

    try {
      // Convert the order to text using a string stream
      std::ostringstream os;
      os << _emp->order(order) << std::endl;
      // Get price of order to convert to std::string
      double price_order = _emp->order(order).price(order);
      double cost_order = _emp->order(order).cost(order);
      // Add money of order paid to cash register
      _emp->cash_register(price_order, cost_order);


      // Display receipt with precision template
      Gtk::MessageDialog dialog{*this, "Order summary: "};
      dialog.set_secondary_text("Receipt: \n" + os.str() + "\n                  Payment of:  $" + to_string_precision(price_order) + "  Required!", true);
      dialog.run();
      dialog.close();

      _emp->order(order).pay();
    }
    catch(std::runtime_error e)
    {
      Gtk::MessageDialog dialog{*this, e.what()};
      dialog.run();
      dialog.close();
      return;
    }
}
