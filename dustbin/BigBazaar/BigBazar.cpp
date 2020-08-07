/*
Author: chankruze (chankruze@geekofia.in)
Created: Thu Aug 06 2020 18:04:20 GMT+0530 (India Standard Time)

Copyright (c) Geekofia 2020 and beyond

*/

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>

#include "product.h"

using namespace std;

double calcDiscount(double* mrp) {
    if (*mrp >= 5000) {
        // discount = 50%
        return *mrp * .5;
    } else if (*mrp >= 2000) {
        // discount = 20%
        return *mrp * .2;
    } else {
        return 0;
    }
}

double calcClothDiscount(double* mrp, int age) {
    if (age >= 40) {
        if (*mrp >= 5000) {
            // discount = 50%
            return *mrp * .5;
        } else if (*mrp >= 2000) {
            // discount = 20%
            return *mrp * .2;
        } else {
            return 0;
        }
    } else if (age >= 20) {
        if (*mrp >= 5000) {
            // discount = 50%
            return *mrp * .6;
        } else if (*mrp >= 2000) {
            // discount = 20%
            return *mrp * .3;
        } else {
            return 0;
        }
    } else {
        if (*mrp >= 2500) {
            // discount = 50%
            return *mrp * .5;
        } else {
            return 0;
        }
    }
}

void genInvoice(vector<Product> cart) {
    double totalPurchageAmount, totalNetPrice;

    srand(time(0));
    int id = rand();
    string fileName = "invoice_" + to_string(id) + ".dat";
    
    time_t now = time(0);
    char* date = ctime(&now);

    system("clear");
    // save invoice
    ofstream invoice;
    invoice.open(fileName, ios::out | ios::binary);

    if (invoice.is_open()) {
        invoice << "\n\n\tBIG BAZAR (GEEKOFIA LTD)" << endl;
        invoice << "\n\t" << date << endl;
        invoice << "\n\tBill ID: " << id << endl;
        invoice << "\n*************** INVOICE ***************" << endl;
        invoice << "S.N.\tTYPE\tPRICE\tDISC\tNET AMT" << endl;

        for (unsigned int i = 0; i < cart.size(); i++) {
            invoice << i + 1 << "\t" << cart[i].getType() << "\t" << cart[i].getPurchageAmount() << "\t" << cart[i].getDiscount() << "\t" << cart[i].getNetPrice() << endl;

            totalPurchageAmount += cart[i].getPurchageAmount();
            totalNetPrice += cart[i].getNetPrice();
        }

        invoice << "\n\nTOTAL PRICE\t: ₹ " << totalPurchageAmount << endl;
        invoice << "TOTAL DISCOUNT\t: ₹ " << totalPurchageAmount - totalNetPrice << " (" << ((totalPurchageAmount - totalNetPrice) / totalPurchageAmount) * 100 << "%)" << endl;
        invoice << "NET PAYABLE AMT\t: ₹ " << totalNetPrice << endl;
    } else {
        cout << "Couldn't save invoice ;( " << fileName << endl;
    }

    invoice.close();
    // print invoice
    string line;
    ifstream invoiceScreen(fileName);
    if (invoiceScreen.is_open()) {
        cout << "\t" << invoiceScreen.rdbuf();
        invoiceScreen.close();
        cout << "\nInvoice is saved to " << fileName << endl;
    } else {
        cout << "Unable to open file";
    }
}

int main(int argc, char const* argv[]) {
    system("clear");
    vector<Product> cart;

    cout << "\tWelcome to BigBazar !" << endl;
    cout << "\nEnter [F] or [f] to Buy Food\nEnter [C] or [c] to Buy Cloth\nEnter [I] or [i] to Generate Invoice\n";

    while (true) {
        char t, keepBuying;
        string type;
        int age, rateOfDiscount;
        double mrp, discount, netPrice;
        Product product;

        cout << "\nAdd Item to Cart [Y/N]: ";
        cin >> keepBuying;

        if (keepBuying == 'Y' || keepBuying == 'y') {
            cout << "\nProduct Type [F/C]: ";
            cin >> t;

            switch (t) {
                case 'F':
                case 'f':
                    type = "Food";

                    cout << "Purchase Amount [Number]: ";
                    cin >> mrp;

                    discount = calcDiscount(&mrp);
                    netPrice = (mrp - discount);

                    // create Product object
                    product.setType(type);
                    product.setPurchageAmount(mrp);
                    product.setDiscount(discount);
                    product.setNetPrice(netPrice);

                    cart.push_back(product);
                    break;

                case 'C':
                case 'c':
                    type = "Cloth";

                    cout << "Purchase Amount [Number]: ";
                    cin >> mrp;

                    cout << "Your Age [Number]: ";
                    cin >> age;

                    discount = calcClothDiscount(&mrp, age);
                    netPrice = (mrp - discount);

                    product.setType(type);
                    product.setPurchageAmount(mrp);
                    product.setDiscount(discount);
                    product.setNetPrice(netPrice);

                    cart.push_back(product);
                    break;

                case 'I':
                case 'i':
                    genInvoice(cart);
                    return 0;

                default:
                    cerr << "\nError: invalid option selected" << endl;
                    return 1;
            }
        } else {
            if (cart.size() != 0) {
                char s;

                cout << "\nGenerate Invoice [Y/N]: ";
                cin >> s;

                if (s == 'Y' || 'y') {
                    genInvoice(cart);
                    return 0;
                } else {
                    return 0;
                }
            } else {
                return 0;
            }
        }
    }

    return 0;
}
