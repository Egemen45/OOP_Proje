//BUSE KONYALI
//18.11.2025


#ifndef MAGAZINE_H
#define MAGAZINE_H
#include <iostream>


#include "Product.h" //üst sınıfın .h ddosyasını ekliyoruz

class Magazine :public Product{//public inheritnge yapılıyor
private:
	int issue;         
	std::string type;


public:

	Magazine(int _ID = 0, std::string name = "", double price = 0.0,int _issue=0,std::string _type=""); //constroctor tanımlanıyor 
	//fonksiyon bildirimleri 
	void printProperties()const; 
	
	int getIssue() const;
	std::string getType() const;
	void setIssue(int issue);

	void setType(std::string type);
	



};



#endif
