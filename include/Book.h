//polymorphisim uygulanmamış hali!!!
#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include<string>

#include "Product.h"//üst sınıfın tanımlı olduğu dosyayı ekliyoruz



class Book : public Product { //inheritage uygulamasını gerçekliştiriyoruz
private:
	std::string author;       //private değişkenlerimizin tanımını yaptık
	std::string publisher;
	int page;
public:
	//fonksiyon tanımlamaları 
	void printProperties();                  //bilgileri yazdıran fonksiyon

	std::string getAuthor()const;              //yazar ismini döndüren fonksiyon   
	void setAuthor(std::string author);        //yazar ismini değiştiren fonksiyon

	std::string getPublisher() const;            //yayın ismini döndüren fonksiyon
	void setPublisher(std::string publisher);   //yayın ismini değiştiren fonksiyon

	int getPage()const;                       //sayfa saısını döndüren fonksiyon
	void setPage(int page);                   //sayfa saısını yeni sayfa ile güncelleyen  fonksiyon
	



};







#endif


