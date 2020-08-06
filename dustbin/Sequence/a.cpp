/*
Author: chankruze (chankruze@geekofia.in)
Created: Fri Aug 07 2020 02:44:16 GMT+0530 (India Standard Time)

Copyright (c) Geekofia 2020 and beyond

*/

#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

void SieveOfEratosthenes(int n, vector<int>* primeArr) {
    // Create a boolean array "prime[0..n]" and initialize
    // all entries it as true. A value in prime[i] will
    // finally be false if i is Not a prime, else true.
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));

    for (int p = 2; p * p <= n; p++) {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true) {
            // Update all multiples of p greater than or
            // equal to the square of it
            // numbers which are multiple of p and are
            // less than p^2 are already been marked.
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

    // Print all prime numbers
    for (int p = 2; p <= n; p++)
        if (prime[p])
            primeArr->push_back(p);
}

// Driver Program to test above function
int main() {
    int n;
    vector<int> primeArr;
    double sum = 1;

    cout << "Enter n: ";
    cin >> n;

    SieveOfEratosthenes(n, &primeArr);

    cout << "1/1";

    for (int i = 0; i < primeArr.size(); i++) {
        sum += (1.0 / primeArr[i]);
        cout << "+1/" << primeArr[i];
    }

    cout << " = " << sum << endl;

    return 0;
}