/*#include "../include/Check.h"
Check::Check(string n, string id) { //if there are parameters assign them to name, bankID,
									//if not use default values
	name = n;
	bankID = id;
}
Check::~Check() {
}
void Check::performPayment() const { //how does the payment occur with check details
	cout << "payment with check from: " << name << " , bank: "<< bankID << " , amount: " << getAmount()<< endl;
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
*/
//Pelin Ece Gerçel 01.12.2025
//www.geeksforgeeks.org/cpp/function-overriding-in-cpp/ ve
//ders notlarindan yararlanilmistir.
//HAVA IŞIKLI 
//08.12.2025 HATA KONTROLLERI EKLENDI
#include "Check.h"
Check::Check(string n, string id) { //if there are parameters assign them to name, bankID,
									//if not use default values
	if(n.empty()){
        cout<<"isim bulunamadi 'Unknown' atamasi yapildi.\n"<<endl;
        n="Unknown";
	}
	name = n;
	if(id.empty()){
        cout<<"bankID bulunamadi '0000' atamasi yapildi.\n"<<endl;
        id="0000";
	}
	bankID = id;
}
Check::~Check() {
}
void Check::performPayment() const { //how does the payment occur with check details
	cout << "payment with check from: " << name << " , bank: "<< bankID << " , amount: " << getAmount()<< endl;
}
string Check::getName() { //return the name of the check owner
	return name;
}
void Check::setName(string n) { //set the name (n) to the check's name
    //bos alan kontrolu
    if(n.empty()){
        cout<<"name bos birakilamaz!!\n"<<endl;
        return;
    }
    //karakter bosluk ya da harf degilse hata mesaji
    for(char c: n){
        if(!isalpha(c)&& !isspace(c)){
            cout<<"hatali karakter girdiniz!!\n"<<endl;
            return;
        }
    }
    //hata kontrolleri gectiyse atama yap
	name = n;
}
string Check::getBankID() { //return the bank ID of the check
	return bankID;
}
void Check::setBankID(string id) { //set the bank ID (id) to the check's bankID
    if (id.empty()) {
        cout << "BankID bos olamaz!!\n"<<endl;
        return;
    }
    //bos degilse atama yapalim
	bankID = id;
}

