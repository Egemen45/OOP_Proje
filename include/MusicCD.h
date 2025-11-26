//polymorphism uygulanmadı
#ifndef MUSICCD_H
#define MUSICCD_H

#include<iostream>
#include "Product.h"

class MusicCD:public Product {
private:
	std::string singer;
	std::string type;
public:
              
	void printProperties()const;             //constu ben ekledim
	std::string getSinger()const;         //constu ben ekledim
	void getSinger(std::string singer);
	std::string getType()const;          //constu ben ekledim
	void setType(std::string type);


};


#endif
