#include <iostream>
#include "Product.h"
using namespace std;


int Product ::getID() const{
	return ID;


}
void Product::setID(int ID) {
	this->ID = ID;


}
std::string Product::getName()const {
	
	return name;


}
void Product:: setName(std::string name) {
	this->name = name;


}
double Product::getPrice()const {

	return price;


}
void Product:: setPeice(double price) {
	this->price = price;


}
void Product::printProperties() {
	cout << "ID: " << ID << endl
		<< "name: " << name << endl
		<< "price: " << price << endl;




}





