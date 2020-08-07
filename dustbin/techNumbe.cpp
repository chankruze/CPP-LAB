/*
Author: chankruze (chankruze@geekofia.in)
Created: Fri Aug 07 2020 15:14:35 GMT+0530 (India Standard Time)

Copyright (c) Geekofia 2020 and beyond

*/
#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[]) {
    for (int i = 1001; i <= 9999; ++i) {
        int leftHalf = i / 100;
        int rightHalf = i % 100;
        int calcPow = pow(leftHalf + rightHalf, 2);

        if (calcPow == i) {
            cout << i << endl;
        }
    }
    return 0;
}
