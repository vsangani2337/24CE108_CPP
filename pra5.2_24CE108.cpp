#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    friend ostream& operator<<(ostream& os, const Complex& c) {
        os << "(" << c.real;
        if (c.imag >= 0)
            os << "+" << c.imag << "i)";
        else
            os << c.imag << "i)";
        return os;
    }

    friend istream& operator>>(istream& is, Complex& c) {
        is >> c.real >> c.imag;
        return is;
    }

    double magnitude() const {
        return sqrt(real * real + imag * imag);
    }

    bool isLargerThan(const Complex& other) const {
        return this->magnitude() > other.magnitude();
    }
};

void displayResults(const Complex& c1, const Complex& c2, const string& approach) {
    cout << "\n" << approach << endl;
    cout << "First : " << c1 << endl;
    cout << "Second : " << c2 << endl;

    Complex sum = c1 + c2;
    Complex difference = c1 - c2;

    cout << "\nSum : " << sum << endl;
    cout << "Difference : " << difference << endl;

    if (c1.isLargerThan(c2)) {
        cout << "\nFirst complex number is larger." << endl;
    } else if (c2.isLargerThan(c1)) {
        cout << "Second complex number is larger." << endl;
    } else {
        cout << "Both complex numbers are equal in magnitude." << endl;
    }
}

int main() {
    Complex c1, c2;

    // Input once
    cout << "Enter first complex number (real imag) : ";
    cin >> c1;
    cout << "Enter second complex number (real imag) : ";
    cin >> c2;

    // STL Vector
    vector<Complex> complexVector = {c1, c2};
    displayResults(complexVector[0], complexVector[1], "Results using STL vector:");

    // Non-STL Array
    Complex* complexArray = new Complex[2];
    complexArray[0] = c1;
    complexArray[1] = c2;
    displayResults(complexArray[0], complexArray[1], "Results using array (non-STL):");

    delete[] complexArray;

    cout << endl << "24CE108_VIVEK_SANGANI" << endl;

    return 0;
}
