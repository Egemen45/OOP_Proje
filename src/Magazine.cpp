#include "Magazine.h"
using namespace std;
#include <iostream>


Magazine::Magazine(int _issue,std::string _type):issue(_issue),type(_type)
{
}
void Magazine:: printProperties()const {

	std::cout<<"Issue: "<<issue<<std::endl;
	std::cout << "Type: " << type << std::endl;
}

int Magazine::getIssue() const {
	return issue;

}
std::string Magazine::getType() const {
	return type;
}
void  Magazine::setIssue(int issue) {
	this->issue = issue;
	
}

void  Magazine::setType(std::string type) {
	this->type = type;

}
