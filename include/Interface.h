#pragma once
#include <string>
#include <iostream>
#include <chrono>
#include <thread>


class Interface {
//buse ekledi
private:
	vector<Customer*> customers;
	vector<Product*> products;

	void addProduct();
	void removeProduct();
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
