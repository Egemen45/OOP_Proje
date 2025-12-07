//HATİCE ŞENBABA
//01.12.2025

#include "Payment.h"
#include <stdexcept>
//gercek odemeler payment sınıfında degil ondan türeyecek olan
// alt siniflarda gerceklestiriecek cunku payment soyut bir siniftir

// constructor
Payment::Payment(double amount)
{
    if (amount < 0) {
        throw std::invalid_argument("Odeme tutari negatif olamaz.");
    }

    this->amount = amount;
}

double Payment::getAmount() const {    // amount degerini dondurur
    return amount;
}

void Payment::setAmount(double amount) {      //amount degeri girme

    if (amount < 0) {
        throw std::invalid_argument("Odeme tutari negatif olamaz.");
    }

    this->amount = amount;
}


