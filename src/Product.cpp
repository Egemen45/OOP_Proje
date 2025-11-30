//BUSE KONYALI
//30.11.2025


#include <iostream>
#include "Product.h"



Product::Product(int _ID , std::string _name , double _price ):ID(_ID),name(_name),price(_price){}//constroctor ile değerler atanıyor

//fonksiyonların içleri dolduruluyor

int Product ::getID() const{
	return ID;

}
void Product::setID(int ID) {
	this->ID = ID;
}

std::string Product::getName()const {	
	return name;
}

void Product:: setName(const std::string& name) {
	this->name = name;
}

double Product::getPrice()const {
	return price;
}

void Product:: setPrice(double price) {
	this->price = price;
}












