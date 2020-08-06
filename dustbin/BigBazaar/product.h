/*
Author: chankruze (chankruze@geekofia.in)
Created: Thu Aug 06 2020 20:05:22 GMT+0530 (India Standard Time)

Copyright (c) Geekofia 2020 and beyond

*/

#ifndef PRODUCT_H
#define PRODUCT_H
#include <iostream>

class Product {
   public:
    // ctor
    Product() {}

    // variables
    std::string type = "Misc";
    double mrp, discount, netPrice;

    // getters
    std::string getType() {
        return this->type;
    };

    double getPurchageAmount() {
        return this->mrp;
    }

    double getDiscount() {
        return this->discount;
    };

    double getNetPrice() {
        return this->netPrice;
    };

    // setters
    void setType(std::string type) {
        this->type = type;
    };

    void setPurchageAmount(double mrp) {
        this->mrp = mrp;
    };

    void setDiscount(double discount) {
        this->discount = discount;
        this->setNetPrice(mrp - discount);
    };

    void setNetPrice(double netPrice) {
        this->netPrice = netPrice;
    };
};

#endif