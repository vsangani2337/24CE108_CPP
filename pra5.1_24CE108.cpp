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

int main() {
    Calculator calc;

    vector<double> stlResults;
    const int SIZE = 3;
    double arrayResults[SIZE];

    int int1, int2;
    double double1, double2;

    cout << "Enter two integers for addition (int, int): ";
    cin >> int1 >> int2;
    double result1 = calc.add(int1, int2);

    cout << "Enter two doubles for addition (double, double): ";
    cin >> double1 >> double2;
    double result2 = calc.add(double1, double2);

    cout << "Enter an integer and a double for addition (int, double): ";
    cin >> int1 >> double1;
    double result3 = calc.add(int1, double1);

    // Store in STL vector
    stlResults.push_back(result1);
    stlResults.push_back(result2);
    stlResults.push_back(result3);

    // Store in Array
    arrayResults[0] = result1;
    arrayResults[1] = result2;
    arrayResults[2] = result3;

    // Display results
    cout << "\nResults using STL Vector:" << endl;
    for (size_t i = 0; i < stlResults.size(); ++i) {
        cout << "Result " << i + 1 << ": " << stlResults[i] << endl;
    }

    cout << "\nResults using Array:" << endl;
    for (int i = 0; i < SIZE; ++i) {
        cout << "Result " << i + 1 << ": " << arrayResults[i] << endl;
    }

    cout << "\n24CE108_VIVEK_SANGANI" << endl;

    return 0;
}
