//BUSE KONYALI
//18.11.2025


#include "../include/Magazine.h"

#include <iostream>


Magazine::Magazine(int _ID , std::string _name , double _price ,int _issue,std::string _type):Product(_ID, _name, _price),issue(_issue),type(_type)//constructor yazılıyor
{
}
void Magazine:: printProperties()const {              //bilgiler yazdırılıyor

	std::cout << "ID: " << getID() << std::endl;                  //product bilgileri yazdırılıyor
	std::cout << "Name: " << getName() << std::endl;
	std::cout << "Price: " << getPrice() << std::endl;
	

	std::cout<<"Issue: "<<issue<<std::endl;            //magazin bilgileri yazdırılıyor
	std::cout << "Type: " << type << std::endl;

}
//fonksiyonların görevleri atanıyor
int Magazine::getIssue() const {
	return issue;

}
std::string Magazine::getType() const {
	return type;
}
void  Magazine::setIssue(int issue) {
	this->issue = issue;
	
}

void  Magazine::setType(const std::string& type) {
	this->type = type;

}

