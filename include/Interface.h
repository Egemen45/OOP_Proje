#pragma once
#include <string>
#include <iostream>
#include <chrono>
#include <thread>
#include <vector>
#include "ShoppingCart.h"


class Interface {
//buse ekledi
private:
	 std::vector<Customer*> customers;
	 std::vector<Product*> products;
	 ShoppingCart shoppingCart;

	 void addProduct();
	 void removeProduct();
	 void allProducts();
	 void login();
	 long setIdFunc();
//buse ekledi son
public:
	 void addCustomerSystemMenu();
	 void showCustomersMenu();
	 void mainMenu();
	 void ItemsMenu();
	 void customerMenu();
	 void startInterface();
	 void ShoppingCartMenu();
	Interface();
	~Interface();
};
