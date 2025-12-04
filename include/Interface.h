#pragma once
#include <string>
#include <iostream>
#include <chrono>
#include <thread>
#include <vector>
#include "ShoppingCart.h"
#include "Book.h"
#include "Magazine.h"
#include "MusicCD.h"


class Interface {
//buse ekledi
private:
	 std::vector<Customer*> customers;
	 std::vector<Product*> products;

	 std::vector<Product*> productsInSystem;
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
