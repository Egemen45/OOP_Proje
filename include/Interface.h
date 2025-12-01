#pragma once
#include <string>
#include <iostream>
#include <chrono>
#include <thread>


class Interface{

public:
	void mainMenu();
	void ItemsMenu();
	void customerMenu();
	void startInterface();
	void ShoppingCartMenu();
	Interface();
    ~Interface();
}