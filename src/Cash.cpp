//HATİCE ŞENBABA
//01.12.2025

#include "../include/Cash.h"
#include <iostream>
#include <stdexcept>


using namespace std;

// constructor: Miras alınan Payment yapıcısını çağırır 
Cash::Cash(double amount) : Payment(amount) {
    if (amount < 0) {                             //hata kontrolu
        throw std::invalid_argument("Odeme tutari negatif olamaz.");
    }
}

// Nakit ödeme yapar
void Cash::performPayment() const {
    
    cout << "        Nakit odeme islemi basariyla gerceklestirildi" <<endl;
    cout << "        Odenen Tutar: " << getAmount() <<endl;
}
