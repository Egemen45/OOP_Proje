#pragma once
#include "product.h"

//EGEMEN ÖZER
//1.12.2025


class ProductToPurchase
{
private : 
	Product* product;
	int quantity;


public : 
	ProductToPurchase();
	~ProductToPurchase();
	Product* getProduct();
	void setProduct(Product* product);
	int getQuantity();
	void setQuantity(int quantity);

};

