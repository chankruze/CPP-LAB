/*
 * Copyright 2019 chankruze <chankruze@geekofia.in>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */

#include <iostream>
using namespace std;

int main() {
	// endl or "\n" is a new line character.
	cout << "\n\n Hello World \n\n";
	cout << "Helo From Geany\n";
	
	// variables
	unsigned int input;
	int sum = 0;
	
	cout << "\n\n User Input & Sum \n\n";
	
	cout << "Please enter a number (1-10) :";
	// user input: extraction operator (>>)
	cin >> input;
	
	// Loop and user input
	if (input < 11) {
		int num;
		for(unsigned int i = 0; i < input; i++) {
			cout << "Enter number " << i + 1 << ":";
			cin >> num;
			sum += num;
		}
		cout << "Sum of User inputs = " << sum << "\n";
	}
	
	// data type sizes //
	cout << "\n\n Data type sizes \n\n";
	
	cout << "Size of char : " << sizeof(char) << " bytes" << endl;
    cout << "Size of int : " << sizeof(int) << " bytes" << endl;
    cout << "Size of short int : " << sizeof(short int) << " bytes" << endl;
    cout << "Size of long int : " << sizeof(long int) << " bytes" << endl;
    cout << "Size of signed long int : " << sizeof(signed long int) << " bytes" << endl;
    cout << "Size of unsigned long int : " << sizeof(unsigned long int) << " bytes" << endl;
    cout << "Size of float : " << sizeof(float) << " bytes" <<endl;
    cout << "Size of double : " << sizeof(double) << " bytes" << endl;
    cout << "Size of long double : " << sizeof(long double) << " bytes" <<endl;
    cout << "Size of wchar_t : " << sizeof(wchar_t) << " bytes" <<endl;
    
    // Doubles //
    cout << "\n\n Doubles \n\n";
    double varDouble = 32.124;
    cout << "varDouble = " << varDouble << "\n";
    
    // Strings //
    cout << "\n\n Strings \n\n";
    
    string str = "I am learning C++";
    cout << "str = " << str << "\n";
    
    // chars //
    cout << "\n\n Chars \n\n";
    
    char charTest = 'S';
    int charTestAscii = charTest;
    
    cout << "charTest = " << charTest << "\n";
    cout << "charTestAscii = " << charTestAscii << "\n";
    
    // Arrays //
    cout << "\n\n Arrays \n\n";
    
    cout << "varDouble = " << varDouble << "\n";
    int arrayOne[] = {11, 45, 62, 70, 88};
    int arrayTwo[5];
    
    for (int i = 0; i < 5; i++){
		arrayTwo[i] = arrayOne[i];
	}
	
	cout << "Array One = ";
	for (int i = 0; i < 5; i++) {
		cout << arrayOne[i] << " ";
	}
	
	cout << "\nArray Two [multiplied 100 to each elem] = ";
	for (int i = 0; i < 5; i++) {
		cout << arrayTwo[i] * 10 << " ";
	}
	
	cout << "\n";
	
	// Arrays //
    cout << "\n\n WHile Loop \n\n";
	unsigned int count = 0;
	while (count < 5) {
		cout << count++ << endl;
	}
	
	// 2D arrays
	int array2d[2][3] = {
		{2, 3, 4}, // 1st row
		{8, 9, 10} // 2nd row
	};
	cout << array2d;
	
	return 0;
}
