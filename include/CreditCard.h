#ifndef CreditCard_h
#define CreditCard_h
//Pelin Ece Gerçel 01.12.2025
//ders notlarindan yararlanilmistir.
#include <string>
#include <iostream>
using namespace std;
#include "Payment.h" //include the Payment.h file for generalization (inheritance) relationship
class CreditCard : public Payment { //parent: Payment, child: Credit Card
									//Credit Card should inherit performPayment() method from Payment

private: //attributes and methods according to the UML diagram
	long number; //credit card number
	string type; //type of the credit card (Visa, MasterCard)
	string expDate; //expiration date of the credit card

public:
	CreditCard(long number = 0, string type = "x", string expDate = "3000"); //constructor with default parameters
	~CreditCard(); //destructor
	void performPayment(); //method from Payment class
	long getNumber(); //get the credit card number
	void setNumber(long); //set the credit card number
	string getType(); //get the type of the credit card
	void setType(string); //set the type of the credit card
	string getExpDate(); //get the expiration date of the credit card
	void setExpDate(string); //set the expiration date of the credit card
};
#endif