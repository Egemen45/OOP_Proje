//BUSE KONYALI
//30.11.2025


#include "Book.h"  //.h dosyasını tanımlıyoruz
#include <iostream>
using namespace std;


//constructor ile değerler başlatılıyor
Book::Book(int _ID , std::string _name , double _price ,std::string _author , std::string _publisher, int _page ):Product(_ID,_name,_price),author(_author),publisher(_publisher),page(_page){}



void Book::printProperties()const {

	cout << "ID: " << getID() << endl;                   //product sınıfının bilgilerini yazdırıyoruz 
	cout << "Name: " << getName() << endl;               //public inheritance sayesinde Book içinde erişim sağladık
	cout << "Price: " << getPrice() << endl;                  

	std::cout << "Author: " << author << std::endl       //Book sınıfının bilgilerini yazdırıyoruz
		      << "Publisher: " << publisher << std::endl
		      << "Page: " << page << std::endl;


}
//fonksiyonların  görevleri yazılıyor
std::string Book::getAuthor() const{

	return author;
}

void Book:: setAuthor(std::string author) {
	this->author = author;

}
std::string Book::getPublisher()const{

	return publisher;
}
void Book::setPublisher(std::string publisher) {
	
	this->publisher = publisher;

}
int Book::getPage() const{
	return page;


}
void Book::setPage(int page) {
	this->page = page;
	
}


