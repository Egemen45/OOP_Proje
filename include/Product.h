//BUSE KONYALI
//30.11.2025


#ifndef PRODUCT_H
#define PRODUCT_H

#include<iostream>

class Product{ //sınıf tanımı
private:
	int ID;
	std::string name;
	double price;
public:
	virtual void printProperties() const= 0;    //soyut sınıf için en az bir tane sanal fonksiyon olmalı 

	Product(int _ID = 0, std::string _name = "", double _price = 0.0); //constructor ile değerleri varsayılan olarak başlatıyoruz

	//fonksiyon prototipleri tanıtılıyor
	int getID()const;
	void setID(int ID);
	std::string getName()const; //sadece değer okuyanlar ,nesnenin değerini değiştirmeyenler const olarak tanımlanıyor
	void setName(std::string name);
	double getPrice()const;
	void setPrice(double price);
	




};
#endif
