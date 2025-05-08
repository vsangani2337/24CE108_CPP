#include <iostream>
#include <limits>
#include <string>
#include <cstdlib>

using namespace std;

bool isValidNumber(const string& input) {
    for (char c : input) {
        if (!isdigit(c) && c != '.' && c != '-') {
            return false;
        }
    }
    return true;
}

double getValidInput(const string& prompt) {
    string input;
    double value;

    while (true) {
        cout << prompt;
        cin >> input;

        if (!isValidNumber(input)) {
            cout << "Invalid input. Please enter a numerical value." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        value = stod(input);
        
        if (value <= 0) {
            cout << "Value must be greater than 0." << endl;
            continue;
        }
        
        break;
    }

    return value;
}

int main() {
    cout << "Welcome to the Financial Calculator!" << endl;

    double loanAmount = getValidInput("Enter the loan amount: ");
    double annualIncome = getValidInput("Enter your annual income: ");

    if (annualIncome == 0) {
        cout << "Error: Annual income cannot be zero." << endl;
        return 1;
    }

    double ratio = loanAmount / annualIncome;
    cout << "Your loan-to-income ratio is: " << ratio << endl;

    cout << "24CE108_VIVEK_SANGANI" << endl;

    return 0;
}
