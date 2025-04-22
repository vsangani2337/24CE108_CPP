#include <iostream>
#include <vector>
using namespace std;

class Calculator {
public:
    double add(int a, int b) {
        return a + b;
    }

    double add(double a, double b) {
        return a + b;
    }

    double add(int a, double b) {
        return a + b;
    }
};

void testWithVector(Calculator& calc) {
    vector<double> results;
    int int1, int2;
    double double1, double2;

    cout << "Enter two integers for the first addition (int, int): ";
    cin >> int1 >> int2;
    results.push_back(calc.add(int1, int2));

    cout << "Enter two doubles for the second addition (double, double): ";
    cin >> double1 >> double2;
    results.push_back(calc.add(double1, double2));

    cout << "Enter an integer and a double for the third addition (int, double): ";
    cin >> int1 >> double1;
    results.push_back(calc.add(int1, double1));

    cout << "\nSTL Results (using 8vector):" << endl;
    for (size_t i = 0; i < results.size(); ++i) {
        cout << "Result " << i + 1 << ": " << results[i] << endl;
    }
}

void testWithArray(Calculator& calc) {
    const int SIZE = 3;
    double results[SIZE];
    int int1, int2;
    double double1, double2;

    cout << "Enter two integers for the first addition (int, int): ";
    cin >> int1 >> int2;
    results[0] = calc.add(int1, int2);

    cout << "Enter two doubles for the second addition (double, double): ";
    cin >> double1 >> double2;
    results[1] = calc.add(double1, double2);

    cout << "Enter an integer and a double for the third addition (int, double): ";
    cin >> int1 >> double1;
    results[2] = calc.add(int1, double1);

    cout << "\nNon-STL Results (using array):" << endl;
    for (int i = 0; i < SIZE; ++i) {
        cout << "Result " << i + 1 << ": " << results[i] << endl;
    }
}

int main() {
    Calculator calc;

    testWithVector(calc);
    testWithArray(calc);

    cout << "24CE108_VIVEK_SANGANI" << endl;

    return 0;
}
