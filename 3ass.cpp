
/*design a c++ class complex with datamenber for real and imaginary partto ....Write aprogram yto perform add 
of two complex no  using operator overloading member function or frnd functiomn */
#include<iostream>
using namespace std;

class Complex {
    float real, img;
public:
    Complex()  // default constructor
    {
        real = 0; 
        img = 0; 
    }         
    Complex(int r, int ig) // parameterized constructor
    { 
        real = r;
        img = ig;
    }  

    void display() 
    {
        cout << real << (img >= 0 ? "+" : "") << img << "i" << endl; // ternary operaator to check the given condition
    }

    // Operator overloads
    Complex operator +(Complex);
    friend Complex operator -(Complex, Complex);
    Complex operator *(Complex);
    Complex operator /(Complex);
};

// Addition (member)
Complex Complex::operator +(Complex C2) {
    Complex C3;
    C3.real = real + C2.real;
    C3.img = img + C2.img;
    return C3;
}

// Subtraction (friend)
Complex operator -(Complex C1, Complex C2) {
    Complex C3;
    C3.real = C1.real - C2.real;
    C3.img = C1.img - C2.img;
    return C3;
}

// Multiplication (member)
Complex Complex::operator *(Complex C2) {
    Complex C3;
    C3.real = (real * C2.real) - (img * C2.img);
    C3.img = (real * C2.img) + (img * C2.real);
    return C3;
}

// Division (member, corrected formula)
Complex Complex::operator /(Complex C2) {
    Complex C3;
    float denom = (C2.real * C2.real) + (C2.img * C2.img);
    C3.real = ((real * C2.real) + (img * C2.img)) / denom;
    C3.img = ((img * C2.real) - (real * C2.img)) / denom;
    return C3;
}

int main() {
    int rr, ig, ch;
    Complex C3;

    cout << "Enter the 1st complex no (real imag): ";
    cin >> rr >> ig;
    Complex C1(rr, ig);

    cout << "Enter the 2nd complex no (real imag): ";
    cin >> rr >> ig;
    Complex C2(rr, ig);

    do {
        cout << "\nCOMPLEX NUMBER OPERATION\n";
        cout << "1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Exit\n";
        cout << "Enter Your Choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                C3 = C1 + C2;
                cout << "Addition result is: ";
                C3.display();
                break;
            case 2:
                C3 = C1 - C2;
                cout << "Subtraction result is: ";
                C3.display();
                break;
            case 3:
                C3 = C1 * C2;
                cout << "Multiplication result is: ";
                C3.display();
                break;
            case 4:
                C3 = C1 / C2;
                cout << "Division result is: ";
                C3.display();
                break;
            case 5:
                cout << "THANK YOU! Goodbye!\n";
                break;
            default:
                cout << "Invalid choice\n";
        }
    } while (ch != 5);

    return 0;
}

