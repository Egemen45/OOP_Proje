//BUSE KONYALI
//30.11.2025

#include "../include/MusicCD.h"
#include <iostream>


//constructor ile değerler başlatılıyor

MusicCD::MusicCD(int _ID , std::string _name , double _price, std::string _singer , std::string _type):Product(_ID, _name, _price), singer(_singer), type(_type){}
//fonksiyonların içleri dolduruluyor
std::string MusicCD::getSinger()const {

	return singer;
}

void MusicCD:: setSinger(const std::string& singer) {

	this->singer = singer;

}

std::string MusicCD::getType() const{

	return type;

}

void MusicCD::setType(const std::string& type){
	this->type = type;

}
//bilgilerin yazdırılması için gerekli fonksiyon
void MusicCD::printProperties() const{

	std::cout << "        ID: " << getID() << std::endl;
	std::cout << "        Name: " << getName() << std::endl;
	std::cout << "        Price: " << getPrice() << std::endl;


	std::cout << "        Singer: " << singer << std::endl;
	std::cout << "        Type: " << type << std::endl;	


}
