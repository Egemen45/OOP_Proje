//HAVA IŞIKLI
//30.11.2025 TASLAK
//06.12.2025 HATA KONTROLLERI

#include "Customer.h"
#include <iostream>
#include <string>
using namespace std;

//varsayılan constructor
Customer::Customer(): customerID(0),name(""),address(""),phone(""),bonus(0),email(""),username(""),password(""){}

// Parametreli Yapıcı
Customer::Customer(long id, const string& n, const string& u, const string& p)
    : customerID(id), name(n), address(""), phone(""), bonus(0.0), email(""), username(u), password(p) {}

// Yıkıcı
Customer::~Customer() {}

//ID FONK
long Customer::getCustomerID()const{
    return customerID;
}
void Customer::setCustomerID(long id){
    // 0 dan buyuk olma kontrolu
    if(id>0)
       customerID=id;
    else
       cout<<"invalid value!!Please enter positive value."<<endl;
}

//name fonk
string Customer::getName()const{
    return name;
}
void Customer::setName(const string& n){
    //bos alan kontrolu
    if(n.empty()){
        cout<<"Isim alani bos birakilamaz!!\n"<<endl;
        return;
    }
    //karakter bosluk ya da harf degilse hata vericem
    for(char c: n){
      if(!isalpha(c) && !isspace(c)){
        cout<<"hatali karakter girdiniz!!\n"<<endl;
        return;
      }
    }
    //hata kontrollerini gectiyse atama yap
        name=n;
}

//address fonk
string Customer::getAddress()const{
    return address;
}
void Customer::setAddress(const string& addr){
    if(!addr.empty()){
        address=addr;
    }else{
        cout<<"adres alani bos birakilamaz!!\n"<<endl;
        return;
    }
}

//phone
string Customer::getPhone()const{
    return phone;
}
void Customer::setPhone(const string& ph){
    //bos olma durum kontrolu
    if(ph.empty()){
        cout<<"telefon alani bos birakilamaz!!\n"<<endl;
        return;
    }
    //sadece sayılardan oluşma kontrolu
    for(char c:ph){
        if(!isdigit(c)){
            cout<<"yalnizca rakamlardan olusmalidir!!\n"<<endl;
            return;
        }
    }
    //kontrolden gectiyse atama yapilsin
    phone=ph;
}

//bonus
double Customer::getBonus()const{
    return bonus;
}
void Customer::setBonus(double b ){
    if(b>= 0.0)
       bonus=b;
    else
       cout<<"bonus negatif olamaz!!\n"<<endl;
}

//email
string Customer::getEmail()const{
    return email;
}
//https://www.geeksforgeeks.org/cpp/stringnpos-in-c-with-examples/
void Customer::setEmail(const string& mail){
    //bos olma durumu kontrol
    if(mail.empty()){
        cout<<"mail alani bos birakilamaz!!\n"<<endl;
        return;
    }
    //'@' icerme durumu kontrolu
    if(mail.find('@')==string::npos){
        cout<< "Email '@' karakteri icermelidir!!\n"<<endl;
        return;
    }
    //'.' icerme durum kontrolu
    if(mail.find('.')==string::npos){
        cout<<"Email '.' karakteri icermelidir!!\n"<<endl;
        return;
    }
    //kontroller tamamsa atama yap
    email=mail;
}

//username
string Customer::getUsername()const{
    return username;
}
void Customer::setUsername(const string& uname){
    //bos olma durum kontrolu
    if(uname.empty()){
        cout<<"username alani bos birakilamaz!!\n"<<endl;
        return;
    }
    //bos degilse atama yap
    username=uname;
}

//password
string Customer::getPassword()const{
    return password;
}
void Customer::setPassword(const string& pass){
    if(pass.empty()){
        cout<<"password alani bos birakilamaz!!\n"<<endl;
        return;
    }
    password=pass;
}

//fatura gönderme
void Customer::sendBill(){
    if(email.empty()){
        cout<<"Email bilgisi bulunamadi ,fatura gonderilemedi!!!\n"<<endl;
        return;
    }
    if(name.empty()){
        cout<<"isim bilgisi bulunamadi ama fatura mail adresine gonderildi.\n"<<endl;
    }
    cout<<"FATURA GONDERILDI::Fatura, "<<name<<" 'nin "<<email<<" adresine gitti."<<endl;
}

//hesap kontrolü
bool Customer::checkAccount(const string& uname,const string& pass)const{
    return(username==uname&&password==pass);
}

//bonus ekle
void Customer::addBonus(double bonusAmount){
    //eklenecek miktarin pozitif olma durum kontrolu
    if(bonusAmount > 0.0){
        bonus += bonusAmount;
        cout<<"tebrikler! hesabiniza "<<bonusAmount<<" bonus yuklendi.yeni bakiyeniz "<<bonus<<endl;
    }else{
        cout<<"bonus miktari pozitif olmalidir!!\n"<<endl;
    }

}
void Customer::useBonus() {
    // Bonus yoksa uyar ve çık
    if (bonus <= 0.0) {
        cout << "Kullanabileceginiz bonus bulunmamaktadir.\n";
        return;
    }

    // Tüm bonusu tek seferde sifirla
    bonus = 0.0;

    cout << "ISLEM BASARILI: Tum bonuslariniz ("
         << bonus << " TL) kullanilmistir. Yeni bakiye: 0 TL.\n";
}

void Customer::printProperties() const {
    cout << "\n        --- Musteri Bilgileri ---" << endl;
    cout << "        ID: " << customerID << endl;
    cout << "        Adi: " << name << endl;
    cout << "        Adres: " << address << endl;
    cout << "        Telefon: " << phone << endl;
    cout << "        E-posta: " << email << endl;
    cout << "        Kullanici Adi: " << username << endl;
    cout << "        Bonus Bakiyesi: " << bonus << " TL" << endl;
    cout << "        --------------------------" << endl;
}
