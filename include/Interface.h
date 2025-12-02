#pragma once
#include <string>
#include <iostream>
#include <chrono>
#include <thread>

#include "ShoppingCart.h"

class Interface {
//buse ekledi
private:
	ShoppingCart shoppingCart;

	vector<Customer*> customers;
	vector<Product*> products;

	
	void allProducts();
	void login();
//buse ekledi son
public:
	void mainMenu();
	void ItemsMenu();
	void customerMenu();
	void startInterface();
	void ShoppingCartMenu();
	Interface();
	~Interface();
};
