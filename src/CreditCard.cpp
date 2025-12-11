//Pelin Ece Gerçel 01.12.2025
//www.geeksforgeeks.org/cpp/function-overriding-in-cpp/ ve
//ders notlarindan yararlanilmistir.
#include "CreditCard.h"
CreditCard::CreditCard(long n, string t, string d) { //if there are parameters assign them to name, type, expDate,
													//if not use default values
	number = n;
	type = t;
	expDate = d;
}
CreditCard::~CreditCard() {
}
void CreditCard::performPayment() const { //how does the payment occur with giving credit card details
	cout << "payment with credit card number: " << number << " , type: " << type <<" , exp: " <<expDate<<" , amount: " << getAmount() << endl;
}
long CreditCard::getNumber() { //return the credit card number
	return number;
}
//hata kontrolleri tamam
void CreditCard::setNumber(long n) { //set the number (n) to the credit card's number
    if(n<0){
        cout<<"kart numarasi negatif olamaz!!\n\n"<<endl;
        return;
    }

    //kontrolden gectiyse atama yap
	number = n;
}
string CreditCard::getType() { //return the type of the credit card
	return type;
}
void CreditCard::setType(string t) { //set the type (t) to the credit card's type
    if(t.empty()){
        cout<<"kart turu bos olamaz !!\n\n"<<endl;
        return;
    }
    //bos degilse atama yap
	type = t;
}
string CreditCard::getExpDate() { //return the expiration date of the credit card
	return expDate;
}
void CreditCard::setExpDate(string d) { //set the expiration date (d) to the credit card's expDate
    if(d.empty()){
        cout<<"ExpDate bos birakilamaz \n\n"<<endl;
        return;
    }
    //kontrol yapildiysa atama yap
	expDate = d;

}


