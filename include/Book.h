//BUSE KONYALI
//30.11.2025

#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include<string>

#include "Product.h"//üst sınıfın tanımlı olduğu dosyayı ekliyoruz



class Book : public Product { //inheritance uygulamasını gerçekliştiriyoruz
private:
	std::string author;       //private değişkenlerimizin tanımını yaptık
	std::string publisher;
	int page;
public:
	//fonksiyon tanımlamaları 

	Book(int _ID=0,std::string _name="",double _price=0.0,std::string _author = "", std::string _publisher = "", int _page = 0);//constroctor varsayılanlarları atanıyor

	void printProperties()const;                  //bilgileri yazdıran fonksiyon abstract sınıftan alındığı için içini doldurmamız gerek

	std::string getAuthor()const;               
	void setAuthor(std::string author);        

	std::string getPublisher() const;            
	void setPublisher(std::string publisher);   

	int getPage()const;                    
	void setPage(int page);                   
	

};
#endif
