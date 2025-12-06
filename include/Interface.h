#pragma once
#include <string>
#include <iostream>
#include <chrono>
#include <thread>
#include <vector>
#include <algorithm>
#include "ShoppingCart.h"
#include "Book.h"
#include "Magazine.h"
#include "MusicCD.h"
#include "Cash.h"
#include "CreditCard.h"
#include "Check.h"

class Interface {
	//buse ekledi
private:
	std::vector<Customer*> customers;

	std::vector<Product*> productsInSystem;
	int globalid = 1;
	ShoppingCart shoppingCart;

	//custemer menu icin yardımcı fonksiyonlar
	bool isValidPhone(const std::string& phone);
	bool isValidEmail(const std::string& email);

	void addProduct();
	void removeProduct();
	void allProducts();
	void login();
	long setIdFunc();
	void updateProducts();
	void searchProducts(int);
	void addProductToSystem(int);
	void addProductMenu();
	void removeProductFromSystem();
	void allProductsInSystem();
	void searchProductMenu();
	//buse ekledi son
public:
	int nextid();
	void addCustomerSystemMenu();
	void showCustomersMenu();
	void mainMenu();
	void ItemsMenu();
	void customerMenu();
	void startInterface();
	void ShoppingCartMenu();
	void paymentMethodMenu();

	Interface();
	~Interface();
};