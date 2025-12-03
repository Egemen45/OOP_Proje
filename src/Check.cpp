#include "Check.h"
Check::Check(string n, string id) { //if there are parameters assign them to name, bankID,
									//if not use default values
	name = n;
	bankID = id;
}
Check::~Check() {
}
void Check::performPayment() { //how does the payment occur with check details
	cout << "payment with check from: " << name << endl;
}
string Check::getName() { //return the name of the check owner
	return name;
}
void Check::setName(string n) { //set the name (n) to the check's name
	name = n;
}
string Check::getBankID() { //return the bank ID of the check
	return bankID;
}
void Check::setBankID(string id) { //set the bank ID (id) to the check's bankID
	bankID = id;
}
