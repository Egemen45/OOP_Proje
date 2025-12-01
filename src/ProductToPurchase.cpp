#include "../include/ProductToPurchase.h"


//EGEMEN ÖZER
//1.12.2025


ProductToPurchase::ProductToPurchase() {};
ProductToPurchase::~ProductToPurchase() =default;



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


