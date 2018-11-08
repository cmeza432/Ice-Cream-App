#ifndef EMPORIUM_H
#define EMPORIUM_H

#include "container.h"
#include "scoop.h"
#include "topping.h"
#include "serving.h"
#include "order.h"
#include "server.h"
#include "customer.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

namespace Mice {

class Emporium {
    public:
        Emporium(std::string name);
        Emporium(std::istream& ist);
        void save(std::ostream& ost);

        std::string name();
        void cash_register(double price, double cost);
        void total_cost(double amount);
        double return_cash_register();
        double return_total_cost();
        std::string total_cost_string();
        std::string cash_register_string();
        void debit(double amount);
        void credit(double amount);
        int next_id();

        int num_containers();
        int num_scoops();
        int num_toppings();
        int num_orders();
        int num_servers();
        int num_customers();

        Container& container(int index);
        Scoop& scoop(int index);
        Topping& topping(int index);
        Order& order(int index);
        Server& server(int index);
        Customer& customer(int index);
        void assign_manager(std::string manager);
        void add_container(Container container);
        void add_scoop(Scoop scoop);
        void add_topping(Topping topping);
        void add_order(Order order);
        void add_server(Server server);
        void add_customer(Customer customer);
        std::string get_containers();
        std::string get_scoops();
        std::string get_toppings();
        std::string get_manager();

    private:
        std::string _name;
        double _cash_register;
        double _total_cost;
        int _id;
        std::string _manager;
        std::vector<Mice::Container> _containers;      // All defined containers
        std::vector<Mice::Scoop> _scoops;              // All defined scoops
        std::vector<Mice::Topping> _toppings;          // All defined toppings
        std::vector<Mice::Order> _orders;              // All defined orders
        std::vector<Mice::Server> _servers;            // All defined servers
        std::vector<Mice::Customer> _customers;        // All defined customers
};

}
#endif
