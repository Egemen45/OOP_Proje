#include "MusicCD.h"
#include <iostream>

std::string MusicCD::getSinger()const {

	return singer;
}

void MusicCD:: getSinger(std::string singer) {

	this->singer = singer;

}

std::string MusicCD::getType() const{

	return type;

}

void MusicCD::setType(std::string type){
	this->type = type;

}
void MusicCD::printProperties() const{
	std::cout << "Singer: " << singer << std::endl;
	std::cout << "Type: " << type << std::endl;	


}
