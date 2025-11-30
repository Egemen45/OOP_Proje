//HATİCE ŞENBABA


#pragma once
#ifndef CASH_H
#define CASH_H

#include "Payment.h"


class Cash : public Payment {     //cash sinifi payment sinifindan türetilmistir
public:
    // constructor
    Cash(double amount = 0.0);

    // destructor
    virtual ~Cash() = default;    //bellek sizintisini önemek ve asamali yikim icin
                                  //sanal yikici

    void performPayment() const override;  //sanal metodu gerceklestirir
};

#endif 

