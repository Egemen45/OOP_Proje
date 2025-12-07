#include "../include/ProductToPurchase.h"


//EGEMEN ÖZER
//1.12.2025


ProductToPurchase::ProductToPurchase() {};
ProductToPurchase::~ProductToPurchase() =default;



int ProductToPurchase::getQuantity() {  //alinacak urunun mikarini donduren fonksiyon
	return quantity;
}
Product* ProductToPurchase::getProduct() {  //alinacak urunu donduren fonksiyon
	return product;
}

void ProductToPurchase::setProduct(Product*product) { //alinacak urunu belirleyen fonksiyon
	this->product = product;
}	
void ProductToPurchase::setQuantity(int quantity) { //alinacak urunun miktarini belirleyen fonksiyon
	this->quantity = quantity;
}


