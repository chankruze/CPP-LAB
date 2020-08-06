/*
Author: chankruze (chankruze@geekofia.in)
Created: Fri Aug 07 2020 03:47:26 GMT+0530 (India Standard Time)

Copyright (c) Geekofia 2020 and beyond

*/
#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    unsigned int n;
    unsigned long long factorial = 1;
    long double sum = 0;

    cout << "Enter n: ";
    cin >> n;

    switch (n) {
        default:
            for (int i = 1; i <= n; ++i) {
                factorial *= i;
                cout << "+1/" << i << "!";
                sum += 1.0 / factorial;
            }
    }

    cout << "\nSum = " << sum << endl;
    return 0;
}
