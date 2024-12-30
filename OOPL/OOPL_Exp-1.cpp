/*
Implement a class Complex which represents the Complex Number data type. Implement 
the following 
1. Constructor (including a default constructor which creates the complex number 0+0i). 
2. Overloaded operator+ to add two complex numbers. 
3. Overloaded operator* to multiply two complex numbers.4. Overloaded << and >> to 
   print and read Complex Numbers.
*/


#include <iostream>
using namespace std;

class Complex {
    float real, img;

public:
    Complex() {
        real = 0;
        img = 0;
    }

    Complex operator+(Complex);
    Complex operator*(Complex);

    friend istream &operator>>(istream &input, Complex &t) {
        cout << "Enter real part of Complex Number: ";
        input >> t.real;
        cout << "Enter imaginary part of Complex Number: ";
        input >> t.img;
        return input;
    }

    friend ostream &operator<<(ostream &output, const Complex &t) {
        output << t.real << "+" << t.img << "i";
        return output;
    }
};

Complex Complex::operator+(Complex C) {
    Complex temp;
    temp.real = real + C.real;
    temp.img = img + C.img;
    return temp;
}

Complex Complex::operator*(Complex C) {
    Complex temp1;
    temp1.real = (real * C.real) - (img * C.img);
    temp1.img = (real * C.img) + (img * C.real);
    return temp1;
}

int main() {
    int ch;
    Complex c1, c2, c3, c4;

    while (true) {
        cout << "\n---MENU---\n";
        cout << "1. Insert Complex Numbers\n";
        cout << "2. Display Complex Numbers\n";
        cout << "3. Addition\n";
        cout << "4. Multiplication\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
        case 1: {
            cout << "Enter 1st Complex Number: \n";
            cin >> c1;
            cout << "Enter 2nd Complex Number: \n";
            cin >> c2;
            break;
        }
        case 2: {
            cout << "1st Complex Number is: " << c1 << endl;
            cout << "2nd Complex Number is: " << c2 << endl;
            break;
        }
        case 3: {
            c3 = c1 + c2;
            cout << "The Addition of " << c1 << " & " << c2 << " is: " << c3 << endl;
            break;
        }
        case 4: {
            c4 = c1 * c2;
            cout << "The Multiplication of " << c1 << " & " << c2 << " is: " << c4 << endl;
            break;
        }
        case 5: {
            cout << "Exiting the program. Goodbye!" << endl;
            return 0;
        }
        default: {
            cout << "Invalid choice. Please try again.\n";
        }
        }
    }

    return 0;
}
