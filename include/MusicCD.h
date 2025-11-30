//BUSE KONYALI
//30.11.2025

#ifndef MUSICCD_H
#define MUSICCD_H

#include<iostream>
#include "Product.h"  //üst sınıfı dahil ediyoruz

class MusicCD:public Product {//inheritance uygulanıyor
private:
	std::string singer;
	std::string type;
public:
	MusicCD(int _ID = 0, std::string _name = "", double _price = 0.0, std::string _singer = "", std::string _type="");
              
	void printProperties()const override;          //nesnenin değerini değiştirmeyen fonksiyonlar const olarak tanımlanıyor

	//fonksiyon bildirimleri yapılıyor
	std::string getSinger()const;        
	void setSinger(const std::string& singer);
	std::string getType()const;          
	void setType(const std::string& type);


};


#endif
