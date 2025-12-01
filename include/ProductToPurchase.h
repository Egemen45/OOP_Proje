#pragma once
#include "product.h"
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

