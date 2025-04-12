#include <iostream>
#include <string>
using namespace std;

class Bank_Account {
private:
    string account_HolderName;
    int account_Number;
    double balance;

public:
    Bank_Account(string name, int acc_Number, double initial_Balance) {
        account_HolderName = name;
        account_Number = acc_Number;
        balance = initial_Balance;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful. New balance: $" << balance << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            cout << "Invalid withdrawal amount!" << endl;
        } else if (amount > balance) {
            cout << "Insufficient balance! Withdrawal failed." << endl;
        } else {
            balance -= amount;
            cout << "Withdrawal successful. Remaining balance: $" << balance << endl;
        }
    }

    void check_Balance() const {
        cout << "Account Holder: " << account_HolderName << endl;
        cout << "Account Number: " << account_Number << endl;
        cout << "Current Balance: $" << balance << endl;
    }
};

int main() {
    Bank_Account customer1("Vivek Sangani", 1001, 5000.00);

    int choice;
    double amount;

    do {
        cout << "--- Banking System Menu ---" << endl;
        cout << "1. Deposit Money" << endl;
        cout << "2. Withdraw Money" << endl;
        cout << "3. Check Balance" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter amount to deposit: $";
            cin >> amount;
            customer1.deposit(amount);
            break;

        case 2:
            cout << "Enter amount to withdraw: $";
            cin >> amount;
            customer1.withdraw(amount);
            break;

        case 3:
            customer1.check_Balance();
            break;

        case 4:
            cout << "Thank you for using the banking system." << endl;
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 4);
    
    cout << "24CE108_VIVEK_SANGANI" << endl;

    return 0;
}
