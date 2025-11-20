#pragma once
#include "ProductToPurchase.h"
#include "Payment.h"
#include "Customer.h"
#include <list>

class ShoppingCart
{
private : 
	std::list<ProductToPurchase*> productsToPurchase;
	Payment* paymentMethod;
	Customer* customer;
	bool isBonusUsed;

public : 
	Payment* getPaymentMethod();
	void setPaymentMethod(Payment* paymentMethod);
	Customer* getCustomer();
	void setCustomer(Customer* customer);
	void setBonusUsed();
	void addProduct(Product* product);
	void removeProduct(Product product);
	void placeOrder();
	void cancelOrder();
	void printProducts();
	void showInvoice();
};

