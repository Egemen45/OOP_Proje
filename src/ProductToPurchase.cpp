#include "../include/ProductToPurchase.h"
#include <iostream>

//HATİCE ŞENBABA
//07.12.2025


ProductToPurchase::ProductToPurchase()
    : product(nullptr), quantity(1)       //ilk deger atamalrı
{
}

ProductToPurchase::~ProductToPurchase() = default;


int ProductToPurchase::getQuantity() {
    return quantity;
}

Product* ProductToPurchase::getProduct() {
    return product;
}

void ProductToPurchase::setProduct(Product* product) {
    if (product == nullptr) {                  //pointer kontrolu
        std::cerr << "HATA: Gecersiz product pointer" << std::endl;
        return;
    }
    this->product = product;
}

void ProductToPurchase::setQuantity(int quantity) {
    if (quantity <= 0) {
        std::cerr << "HATA: quantity sifirdan buyuk olmalidir." << std::endl;
        return;
    }
    this->quantity = quantity;
}




