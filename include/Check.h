#ifndef Check_h
#define Check_h
//Pelin Ece Gerçel 01.12.2025
//ders notlarindan yararlanilmistir.
#include <string>
#include <iostream>
using namespace std;
#include "Payment.h" //include the Payment.h file for generalization (inheritance) relationship
class Check : public Payment { //parent: Payment, child: Check
								//Check should inherit performPayment() method from Payment

private: //attributes and methods according to the UML diagram
	string name; //name of the check owner
	string bankID; //bank ID of the check

public:
	Check(string name = "a", string bankID = "b"); //constructor with default parameters
	~Check(); //destructor
	void performPayment(); //method from Payment class
	string getName(); //get the name of the check owner
	void setName(string); //set the name of the check owner
	string getBankID(); //get the bank ID of the check
	void setBankID(string); //set the bank ID of the check
};
#endif