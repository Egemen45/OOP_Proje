#include "Payment.h"

//gercek odemeler payment sınıfında degil ondan türeyecek olan 
// alt siniflarda gerceklestiriecek cunku payment soyut bir siniftir

// constructor 
Payment::Payment(double amount) : amount(amount) {}

double Payment::getAmount() const {     // amount degerini dondurur
    return amount;
}


void Payment::setAmount(double amount) {   //amount degeri girme
    this->amount = amount;
}

