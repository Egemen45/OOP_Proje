#include "../include/ProductToPurchase.h"



int ProductToPurchase::getQuantity() {
	return quantity;
}
Product* ProductToPurchase::getProduct() {
	return product;
}

void ProductToPurchase::setProduct(Product*product) {
	this->product = product;
}	
void ProductToPurchase::setQuantity(int quantity) {
	this->quantity = quantity;
}


