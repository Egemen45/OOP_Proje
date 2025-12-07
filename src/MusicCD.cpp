//BUSE KONYALI
//30.11.2025

//HATİCE ŞENBABA
//07.12.2025 -- HATA KONTROLLERİ EKLENDİ

#include "../include/MusicCD.h"
#include <iostream>
#include <string>

//constructor ile değerler başlatılıyor

MusicCD::MusicCD(int _ID , std::string _name , double _price, std::string _singer , std::string _type):Product(_ID, _name, _price), singer(_singer), type(_type){}
//fonksiyonların içleri dolduruluyor
std::string MusicCD::getSinger()const {

	return singer;
}

void MusicCD:: setSinger(const std::string& singer) {

	if (!singer.empty()) {               //sanatci adi kontrolu
	    this->singer = singer;
    } else {
        std::cerr << "HATA: Sanatci adi bos olamaz" << std::endl;
    }

}

std::string MusicCD::getType() const{

	return type;

}

void MusicCD::setType(const std::string& type){
	if (!type.empty()) {                  // muzik turu bos mu kontrolu
	    this->type = type;
    } else {
        std::cerr << "HATA: Muzik turu bos olamaz" << std::endl;
    }

}
//bilgilerin yazdırılması için gerekli fonksiyon
void MusicCD::printProperties() const{

	std::cout << "        ID: " << getID() << std::endl;
	std::cout << "        Name: " << getName() << std::endl;
	std::cout << "        Price: " << getPrice() << std::endl;


	std::cout << "        Singer: " << singer << std::endl;
	std::cout << "        Type: " << type << std::endl;	


}
