//HATİCE ŞENBABA

#include "../include/Cash.h"
#include <iostream>

using namespace std;

// Miras alınan Payment yapıcısını çağırır
Cash::Cash(double amount) : Payment(amount) {};

// Nakit ödeme yapar
void Cash::performPayment() const {
    
    cout << " Nakit odeme islemi basariyla gerceklestirildi" <<endl;
    cout << " Odenen Tutar: " << getAmount() <<endl;
}
