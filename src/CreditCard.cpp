#include "../include/CreditCard.h"
CreditCard::CreditCard(long n, string t, string d) { //if there are parameters assign them to name, type, expDate,
													//if not use default values
	number = n;
	type = t;
	expDate = d;
}
CreditCard::~CreditCard() {
}
void CreditCard::performPayment() { //how does the payment occur with giving credit card details
	cout << "payment with credit card number: " << number << " type: " << type << endl;
}
long CreditCard::getNumber() { //return the credit card number
	return number;
}
void CreditCard::setNumber(long n) { //set the number (n) to the credit card's number
	number = n;
}
string CreditCard::getType() { //return the type of the credit card
	return type;
}
void CreditCard::setType(string t) { //set the type (t) to the credit card's type
	type = t;
}
string CreditCard::getExpDate() { //return the expiration date of the credit card
	return expDate;
}
void CreditCard::setExpDate(string d) { //set the expiration date (d) to the credit card's expDate
	expDate = d;
}