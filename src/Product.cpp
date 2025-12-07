//BUSE KONYALI
//30.11.2025

//HATİCE ŞENBABA 
//07.12.2025 -- hata kontrolleri yapildi

#include <iostream>
#include "../include/Product.h"



Product::Product(int _ID , std::string _name , double _price ):ID(_ID),name(_name),price(_price){}//constroctor ile değerler atanıyor

//fonksiyonların içleri dolduruluyor

int Product ::getID() const{
	return ID;

}
void Product::setID(int ID) {
	if (ID > 0) {
	    this->ID = ID;
    } else {
        std::cerr << "HATA: ID sifirdan buyuk olmalidir" << std::endl;
    }
}

std::string Product::getName()const {	
	return name;
}

void Product:: setName(const std::string& name) {
	 if (!name.empty()) {
	    this->name = name;
    } else {
        std::cerr << "HATA: Urun adi bos olamaz" << std::endl;
    }
}

double Product::getPrice()const {
	return price;
}

void Product:: setPrice(double price) {
	if (price >= 0.0) {
	    this->price = price;
    } else {
        std::cerr << "HATA: Fiyat negatif olamaz" << std::endl;
    }
}












