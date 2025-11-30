#include "Customer.h"
#include <iostream>
#include <string>
#include <algorithm>//all_of için
#include <cctype>//isalpha,isdigit için
using namespace std;
//varsayılan constructor
Customer::Customer(): customerID(0),name(""),address(""),phone(""),bonus(0),email(""),username(""),password(""){}

// Parametreli Yapıcı (Özellikle zorunlu alanlar için)
Customer::Customer(long id, const string& n, const string& u, const string& p)
    : customerID(id), name(n), address(""), phone(""), bonus(0.0), email(""), username(u), password(p) {}

// Yıkıcı
Customer::~Customer() {
    // Kaynak temizliği gerekirse buraya eklenir.
}

//ID FONK
long Customer::getCustomerID()const{
    return customerID;
}
void Customer::setCustomerID(long id){
    customerID=id;
}

//name fonk
string Customer::getName()const{
    return name;
}
void Customer::setName(const string& n){
    name=n;
}

//address fonk
string Customer::getAddress()const{
    return address;
}
void Customer::setAddress(const string& addr){
    address=addr;
}

//phone
string Customer::getPhone()const{
    return phone;
}
void Customer::setPhone(const string& ph){
    phone=ph;
}

//bonus
double Customer::getBonus()const{
    return bonus;
}
void Customer::setBonus(double b ){
    bonus=b;
}

//email
string Customer::getEmail()const{
    return email;
}
void Customer::setEmail(const string& mail){
    email=mail;
}

//username
string Customer::getUsername()const{
    return username;
}
void Customer::setUsername(const string& uname){
    username=uname;
}

//password
string Customer::getPassword()const{
    return password;
}
void Customer::setPassword(const string& pass){
    password=pass;
}

//fatura gönderme
void Customer::sendBill(){
    cout<<"fatura, "<<name<<" 'nin "<<email<<" adresine gitti."<<endl;
}

//hesap kontrolü
bool Customer::checkAccount(const string& uname,const string& pass)const{
    return(username==uname&&password==pass);
}

//bonus ekle
void Customer::addBonus(double bonusAmount){
    bonus += bonusAmount;
    cout<<"tebrikler! hesabiniza "<<bonusAmount<<" bonus yuklendi.yeni bakiyeniz "<<bonus<<endl;
}
void Customer::useBonus(){
    cout<<"mevcut "<<bonus<<"tl tutari bonusunuz kullanildi ve bakiyeniz sifirlandi."<<endl;
    bonus=0.0;
}

void Customer::printProperties() const {
    cout << "\n--- Müşteri Bilgileri ---" << endl;
    cout << "ID: " << customerID << endl;
    cout << "Adı: " << name << endl;
    cout << "Adres: " << address << endl;
    cout << "Telefon: " << phone << endl;
    cout << "E-posta: " << email << endl;
    cout << "Kullanıcı Adı: " << username << endl;
    // Güvenlik nedeniyle şifreyi yazdırmamak daha iyi bir pratik olsa da,
    // talep üzerine ekliyorum:
    cout << "Şifre: " << password << endl;
    cout << "Bonus Bakiyesi: " << bonus << " TL" << endl;
    cout << "--------------------------" << endl;
}
