#pragma once
#include "ProductToPurchase.h"
#include "Payment.h"
#include "Customer.h"
#include <vector>
#include <chrono>
#include <thread>
//EGEMEN ÖZER
//1.12.2025


class ShoppingCart
{
private : 
	std::vector<ProductToPurchase*> productsToPurchase;
	Payment* paymentMethod;
	Customer* customer;
	bool isBonusUsed;


public : 
	ShoppingCart();
	Payment* getPaymentMethod();
	void setPaymentMethod(Payment* paymentMethod);
	Customer* getCustomer(); 
	void setCustomer(Customer* customer);
	void setBonusUsed();
	void addProduct(ProductToPurchase*); 
	void removeProduct(ProductToPurchase*);
	void placeOrder();
	void cancelOrder();
	void printProducts(); 
	void showInvoice(); 
	~ShoppingCart();
};

