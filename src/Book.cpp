
#include "Book.h"
#include <iostream>


void Book::printProperties() {
	std::cout << "Author: " << author << std::endl
		      << "Publisher: " << publisher << std::endl
		      << "Page: " << page << std::endl;


}
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

