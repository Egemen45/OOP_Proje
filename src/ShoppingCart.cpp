#include "../include/ShoppingCart.h"



ShoppingCart::ShoppingCart() : isBonusUsed(false) {}; //isBonusUsed baslangýcta false olarak ayarlandi

Customer * ShoppingCart::getCustomer() { // customer nesnesini dondurur
	return customer;
}

Payment* ShoppingCart::getPaymentMethod() { //paymentMethodu dondurur
	return paymentMethod;
}


void ShoppingCart::setPaymentMethod(Payment* paymentMethod) {  //payment method shoppingcart nesnesine atandi

	this->paymentMethod = paymentMethod;


}
void ShoppingCart::setCustomer(Customer* customer) { //customeri nesnede bulunan customer degiskenine atadik

	this->customer = customer;


}
void ShoppingCart::setBonusUsed() { //bonus kullanilacaksa isBonusUsed true olur

	isBonusUsed = true;


}

void ShoppingCart::addProduct(ProductToPurchase*productToPurchase){ 
	productsToPurchase.push_back(productToPurchase); //alinacak urunu alisveris sepetimize atiyoruz

}

void ShoppingCart::removeProduct(ProductToPurchase* productToPurchase) { //alisveris sepetinden alinacak urunu kaldirmak istiyoruz
	int size = productsToPurchase.size(); // alisveris sepetimizin boyutuna bakiyoruz

	if (size == 0) {
		std::cout << "Shopping cart is already empty" << std::endl;
	}
	else {
		for (int i = 0; i < size; i++)
		{


		}
	}



	


}

void ShoppingCart::printProducts() {

	std::cout << "***** Inside of the cart *****" << std::endl;

	for (int i = 0; i < productsToPurchase.size(); i++)
	{
		std::cout<<productsToPurchase[i]->getProduct<<std::endl; //yapim asamasinda

	}

}



