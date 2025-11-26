//polymorphisim uygulanmamış hali!!!
#ifndef MAGAZINE_H
#define MAGAZINE_H
#include <iostream>


#include "Product.h"

class Magazine :public Product{
private:
	int issue;         
	std::string type;


public:

	Magazine(int _issue=0,std::string _type="");

	void printProperties()const;
	
	int getIssue() const;
	std::string getType() const;
	void setIssue(int issue);

	void setType(std::string type);
	



};







#endif
