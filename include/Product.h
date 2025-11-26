//soyut sınıf kısmı yok

#ifndef PRODUCT_H
#define PRODUCT_H

#include<iostream>

class Product{
private:
	int ID;
	std::string name;
	double price;
public:
	int getID()const;
	void setID(int ID);
	std::string getName()const;
	void setName(std::string name);
	double getPrice()const;
	void setPeice(double price);
	void printProperties();




};
#endif
