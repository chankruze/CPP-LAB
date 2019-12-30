# Notes

## Template

```cpp
#include <iostream>
using namespace std;

int main() {
  reurn 0;
}
```

## Data Type Cheet Table

Datatypes | Size (bytes) | Lower limit | Higher limit
----------|--------------|-------------|----------
char | 1 | -127 | 127
unsigned char | 1 | 0 | 255
int | 4 | -32,767 | 32,767
short int | 2 | -32,767 | 32,767
long int | 8 | -2,147,483,647 | 2,147,483,647
long long int | 8 | -9,223,372,036,854,775,807 | 9,223,372,036,854,775,807
unsigned int | 4 | 0 | 65,535
unsigned short int | 2 | 0 | 65,535
unsigned long int | 8 | 0 | 4,294,967,295
unsigned long long int | 8 | 0 | 18,446,744,073,709,551,615
float | 4 |
double | 8 |
long double | 16 |
bool | 1 |
string | 32 |
wchar_t | 4 |

## Main function

```cpp
// 1
int main () { body }

// 2
int main (int argc, char *argv[]) { body }
```

- **argc**	-	Non-negative value representing the number of arguments passed to the program from the environment in which the program is run.

- **argv**	-	Pointer to the first element of an array of `argc + 1` pointers, of which the last one is null and the previous ones, if any, point to null-terminated multibyte strings that represent the arguments passed to the program from the execution environment. If `argv[0]` is not a null pointer (or, equivalently, if `argc > 0)`, it points to a string that represents the name used to invoke the program, or to an empty string.

- **body**	-	The body of the main function

The names `argc` and `argv` are arbitrary, as well as the representation of the types of the parameters: `int main(int ac, char** av)` is equally valid.


## Arrays

### 1D Arrays

**Initialization**

```cpp
// 1
int arr[] = {11, 45, 62, 70, 88};

// 2 (From user input)
int size;
cin >> size;

int arr[size];

for (int i = 0; i < size; i++) {
    cin >> arr[i];
}
```
### 2D Arrays

**Initialization**

__*Note: Declaration of multidimensional array must have bounds for all dimensions except the first*__


```cpp
// 1
int x[2][3] = {
  {2, 3, 4}, // 1st row
  {8, 9, 10} // 2nd row
};

// also valid
int x[][3] = {
  {2, 3, 4}, // 1st row
  {8, 9, 10} // 2nd row
};

// 2 (From user input)
int rows, columns;
cin >> rows;
cin >> columns;

int arr[rows][columns];

for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
        cin >> arr[i][j];
    }
}
```

## Pointers

**Def**: A pointer is a variable, with the address of another variable as its value.

**Data Type**: `long` hexadecimal number (i.e. 0x29fee8)

**Operators**
- **Address-of** (`&`): returns the memory address of its operand.
- **Contents-of** (`*`): returns the value of the variable located at the address specified by its operand.

**Declartion**
```cpp
int *ip;  // pointer to an integer
double *dp;   // pointer to a double
float *fp;  // pointer to a float
char *ch;  // pointer to a character
```

**Example**
```cpp
int var = 50;
int  *p = &var;

cout << var << endl;
// Outputs 50 (the value of var)

cout << p << endl;
// Outputs 0x29fee8 (var's memory location)

cout << *p << endl;
/* Outputs 50 (the value of the variable
 stored in the pointer p) */
```

__*Note:*__: The asterisk (*) is used in declaring a pointer for the simple purpose of indicating that it is a pointer (The asterisk is part of its type compound specifier). Don't confuse this with the dereference operator, which is used to obtain the value located at the specified address. They are simply two different things represented with the same sign.


## Dynamic Memory
In a C++ program, memory is divided into two parts:
1. **The stack**: All of your local variables take up memory from the stack.
1. **The heap**: Unused program memory that can be used when the program runs to dynamically allocate the memory.

You can allocate memory at run time within the heap for the variable of a given type using the `new` operator, which returns the address of the space allocated.

The allocated address can be stored in a pointer, which can then be dereferenced to access the variable.

On the heap, it's necessary to manually handle the dynamically allocated memory, and use the `delete` operator to free up the memory when it's no longer needed.

The delete operator frees up the memory allocated for the variable, but does not delete the pointer itself, as the pointer is stored on the stack.

**Dangling Pointers**: Pointers that are left pointing to non-existent memory locations.

```cpp
int *p = new int; // request memory
*p = 5; // store value

delete p; // free up the memory
// now p is a dangling pointer

p = new int; // reuse for a new address
```

**NULL** is a constant with a value of zero. It's a good practice to assign __NULL__ to a pointer variable while declaring.

**For arrays**
```cpp
int *p = NULL; // Pointer initialized with null
p = new int[20]; // Request memory
delete [] p; // Delete array pointed to by p
```

## Functions

Function declaration is required when you define a function in one source file and you call that function in another file. In such case, you should declare the function at the top of the file calling the function.

```cpp
#include <iostream>
using namespace std;

//Function declaration
void printSomething();

int main() {
  printSomething();

  return 0;
}

//Function definition
void printSomething() {
  cout << "Hi there!";
}
```
Data type and name should be defined for each parameter.

multiple parameters are separated with commas, both when declaring them and when passing the arguments.

**Formal parameters** are created upon entering the function, and are destroyed upon exiting the function.

Making changes to the parameter within the function does not alter the argument.

## Default Values for Parameters

```cpp
int volume(int l = 1, int w = 1, int h = 1) {
  return l * w * h;
}

int main() {
  cout << volume() << endl;
  cout << volume(5) << endl;
  cout << volume(2, 3) << endl;
  cout << volume(3, 7, 6) << endl;
}

/* Output
1
5
6
126
*/
```

## Random Numbers

**Include**: C++ standard library `<cstdlib>`

### pseudo random numbers

**Function name**: `rand()`

This means that each time the code is run, it generates the same numbers.

```cpp
#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
  cout << rand();
}
```

**modulo (%)** operator can be used to generate random numbers within a specific range.

```cpp
for (int x = 1; x <= 10; x++) {
  // in range 1 to 10 (inclusive)
  cout << 1 + (rand() % 10) << endl;
}
```

**Function name**: `srand()`

This function allows to specify a seed value as its parameter, which is used for the rand() function's algorithm.

Changing the **seed** value changes the return of rand(). However, the same seed will result in the same output.

```cpp
srand(98);

for (int x = 1; x <= 10; x++) {
  cout << 1 + (rand() % 6) << endl;
}
```

### truly random numbers

A solution to generate truly random numbers, is to use the current time as a seed value for the srand() function.

`time(0)` returns the current second count.

```cpp
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main () {
  srand(time(0));

  for (int x = 1; x <= 10; x++) {
    cout << 1 + (rand() % 6) << endl;
  }
}
```

## Function Overloading

Function overloading allows to create multiple functions with the same name, so long as they have different parameters.

When overloading functions, the definition of the function must differ from each other by the types and/or the number of arguments in the argument list.

Example:
```cpp
void printNumber(int x) {
    cout << "Prints an integer: " << x << endl;
}
void printNumber(float x) {
    cout << "Prints a float: " << x << endl;
}
int main() {
  int a = 16;
  float b = 54.541;
  printNumber(a);
  printNumber(b);
}

/* Output:  
Prints an integer: 16
Prints a float: 54.541
*/
```

You can not overload function declarations that differ only by return type.

```cpp
// Wrong
int printName(int a) { }
float printName(int b) { }
double printName(int c) { }
```