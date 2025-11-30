#pragma once
#ifndef PAYMENT_H
#define PAYMENT_H


class Payment {
private:
    double amount; // odeme tutari

public:
    // constructor 
    Payment(double amount = 0.0);

    // destructor
    virtual ~Payment() = default;       //bellek sizitisini önlemek icin sanal yikici kullandik

    double getAmount() const;           //kapsulleme ile veri okuma 

    void setAmount(double amount);      //kapsulleme ile vei yazma disardan private degiskene erisim
  
    virtual void performPayment() const = 0;   //dinamik baglanma icin saf sanal baglanma
                                               //alt siniflarda da otomatik olarak gerceklestirilecek
};

#endif 

