//BUSE KONYALI
//30.11.2025

//HAVA IŞIKLI
//7.12.2025 --HATA KONTROLLERİ

#include "Book.h"  //.h dosyasını tanımlıyoruz
#include <iostream>
#include <stdexcept>//hatalar için(throw)


//constructor ile değerler başlatılıyor
Book::Book(int _ID , std::string _name , double _price ,std::string _author , std::string _publisher, int _page ):Product(_ID,_name,_price){

//yazar adi bos mu kontrolu
  if(_author.empty()){
    throw std::invalid_argument("HATA:yazar alani bos olamaz!!\n");
  }
  //publisher alani bos mu
  if(_publisher.empty()){
    throw std::invalid_argument("HATA:yayinci alani bos olamaz!!\n");
  }
  //page pozitif mi
  if(_page<=0){
    throw std::invalid_argument("HATA:sayfa sayisi pozitif olmalidir!!\n");
  }
//tüm kontrollerden gectiyse atamaları yap
  this->author=_author;
  this->publisher=_publisher;
  this->page=_page;
}
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
    //bos olma kontrolu
    if(author.empty()){
        throw std::invalid_argument("HATA:yazar adi bos birakilamaz.\n");
    }
    //bos degilse atama yapalim
	this->author = author;

}
std::string Book::getPublisher()const{

	return publisher;
}
void Book::setPublisher(const std::string& publisher) {
    //bos olma kontrolu
    if(publisher.empty()){
        throw std::invalid_argument("HATA: yayinci alani bos birakilamaz!!\n");
    }
    //bos degilse atama yapalım
	this->publisher = publisher;

}
int Book::getPage() const{
	return page;


}
void Book::setPage(int page) {
    //sayfa kontrolu
    if(page<=0){
        throw std::invalid_argument("HATA: Sayfa sayisi negatif veya 0 olamaz!");
    }
    //kontrolu gectiyse atama yap
	this->page = page;

}
