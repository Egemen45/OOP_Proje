//BUSE KONYALI
//30.11.2025

#include "MusicCD.h"
#include <iostream>
using namespace std;

//constructor ile ddeğerler başlatılıyor

MusicCD::MusicCD(int _ID , std::string _name , double _price, std::string _singer , std::string _type):Product(_ID, _name, _price), singer(_singer), type(_type){}
//fonksiyonların içleri dolduruluyor
std::string MusicCD::getSinger()const {

	return singer;
}

void MusicCD:: setSinger(std::string singer) {

	this->singer = singer;

}

std::string MusicCD::getType() const{

	return type;

}

void MusicCD::setType(std::string type){
	this->type = type;

}
//bilgilerin yazdırılması için gerekli fonksiyon
void MusicCD::printProperties() const{

	cout << "ID: " << getID() << endl;
	cout << "Name: " << getName() << endl;
	cout << "Price: " << getPrice() << endl;


	std::cout << "Singer: " << singer << std::endl;
	std::cout << "Type: " << type << std::endl;	


}
