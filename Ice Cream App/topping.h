#ifndef _TOPPING_H
#define _TOPPING_H

#include "item.h"
#include <iostream>
#include <fstream>

namespace Mice {

class Topping : public Item {
  public:
    Topping(std::string name, std::string description, double cost, double price,
              int amount);
    Topping(std::istream& ist);
    void save(std::ostream& ost);
    std::string type() const override;
    int amount() const;
    const static int LIGHT_AMOUNT = 1;
    const static int NORMAL_AMOUNT = 2;
    const static int EXTRA_AMOUNT = 3;
    const static int DRENCHED_AMOUNT = 4;
  private:
    void _set_amount(int amount);
    int _amount;
};

}
#endif
