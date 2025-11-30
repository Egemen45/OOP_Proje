//BUSE KONYALI
//30.11.2025


#include "Book.h"  //.h dosyasını tanımlıyoruz
#include <iostream>


//constructor ile değerler başlatılıyor
Book::Book(int _ID , std::string _name , double _price ,std::string _author , std::string _publisher, int _page ):Product(_ID,_name,_price),author(_author),publisher(_publisher),page(_page){}



void Book::printProperties()const {

	std::cout << "ID: " << getID() << std::endl;                   //product sınıfının bilgilerini yazdırıyoruz 
	std::cout << "Name: " << getName() << std::endl;               //public inheritance sayesinde Book içinde erişim sağladık
	std::cout << "Price: " << getPrice() << std::endl;

	std::cout << "Author: " << author << std::endl              //Book sınıfının bilgilerini yazdırıyoruz
		      << "Publisher: " << publisher << std::endl
		      << "Page: " << page << std::endl;


}
//fonksiyonların  görevleri yazılıyor
std::string Book::getAuthor() const{

	return author;
}

void Book:: setAuthor(const std::string& author) {
	this->author = author;

}
std::string Book::getPublisher()const{

	return publisher;
}
void Book::setPublisher(const std::string& publisher) {
	
	this->publisher = publisher;

}
int Book::getPage() const{
	return page;


}
void Book::setPage(int page) {
	this->page = page;
	
}



