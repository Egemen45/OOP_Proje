#pragma once
#include "ProductToPurchase.h"
#include "Payment.h"
#include "Customer.h"
#include <vector>

class ShoppingCart
{
private : 
	std::vector<ProductToPurchase*> productsToPurchase;
	Payment* paymentMethod;
	Customer* customer;
	bool isBonusUsed;

	ShoppingCart();//tmm

public : 
	Payment* getPaymentMethod();//tmm
	void setPaymentMethod(Payment* paymentMethod);//tmm
	Customer* getCustomer(); //tmm
	void setCustomer(Customer* customer);//tmm
	void setBonusUsed();//tmm
	void addProduct(ProductToPurchase*); //tmm
	void removeProduct(ProductToPurchase*);//tmm
	void placeOrder();
	void cancelOrder();
	void printProducts(); //tmm
	void showInvoice(); //
};

