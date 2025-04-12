#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

class Loan {
private:
    int loanID;
    string applicantName;
    double loanAmount;
    double annualInterestRate;
    int tenureMonths;

public:
    Loan() {
        loanID = 0;
        applicantName = "Default Applicant";
        loanAmount = 100000;
        annualInterestRate = 10.0;
        tenureMonths = 12;
    }

    Loan(int id, string name, double amount, double rate, int months) {
        loanID = id;
        applicantName = name;
        loanAmount = amount;
        annualInterestRate = rate;
        tenureMonths = months;
    }

    void get_data() {
        cout << endl << "Enter Loan Details:" << endl;
        cout << "Loan ID: ";
        cin >> loanID;
        cin.ignore();
        cout << "Applicant Name: ";
        getline(cin, applicantName);
        cout << "Loan Amount: ";
        cin >> loanAmount;
        cout << "Annual Interest Rate (%): ";
        cin >> annualInterestRate;
        cout << "Tenure (in months): ";
        cin >> tenureMonths;
    }

    double calculateEMI() const {
        double P = loanAmount;
        double R = annualInterestRate / (12 * 100);
        int T = tenureMonths;

        double numerator = P * R * pow(1 + R, T);
        double denominator = pow(1 + R, T) - 1;
        double emi = numerator / denominator;

        return emi;
    }

    void displayLoanDetails() const {
        cout << fixed << setprecision(2);
        cout << endl << "----- Loan Summary -----" << endl;
        cout << "Loan ID           : " << loanID << endl;
        cout << "Applicant Name    : " << applicantName << endl;
        cout << "Loan Amount       : " << loanAmount << endl;
        cout << "Annual Interest   : " << annualInterestRate << "%" << endl;
        cout << "Tenure            : " << tenureMonths << " months" << endl;
        cout << "Monthly EMI       : " << calculateEMI() << endl;
    }
};

int main() {
    cout << "Default Loan Details (for testing):" << endl;
    Loan defaultLoan;
    defaultLoan.displayLoanDetails();

    Loan userLoan;
    userLoan.get_data();
    userLoan.displayLoanDetails();

    cout <<"24CE108_VIVEK_SANGANI" << endl;
    return 0;
}
