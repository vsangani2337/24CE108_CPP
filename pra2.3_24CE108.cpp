#include <iostream>
#include <string>
using namespace std;

class BankAccount {
    string holder_name;
    int account_number;
    float balance;

public:

    BankAccount(string name = "", int acc_number = 0, float bal = 0) {
        holder_name = name;
        account_number = acc_number;
        balance = bal;
    }

    void get_data() {
        cout << " ---------------------------------------" << endl;
        cout << "   Enter account holder name: ";
        cin >> holder_name;
        cout << "   Enter account number: ";
        cin >> account_number;
        cout << "   Enter initial balance: ";
        cin >> balance;
        cout << " ---------------------------------------" << endl;
    }

    void put_data() {
        cout << "Name: " << holder_name << endl;
        cout << "Account Number: " << account_number << endl;
        cout << "Balance: " << balance << endl;
    }

    int get_account_number() {
        return account_number;
    }
};

int main() {
    int choice;
    BankAccount accounts[3];
    int accountCount = 0;
    int selectedAccount = -1;

    cout << "Welcome To The Bank" << endl;

    do {
        cout << " ---------------------------------" << endl;
        cout << "|   1. Information of account     |" << endl;
        cout << "|   2. Add new account            |" << endl;
        cout << "|   3. Select account             |" << endl;
        cout << "|   0. Exit                       |" << endl;
        cout << " ---------------------------------" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 0:
                cout << "Thanks for visiting !!" << endl;
                break;

            case 1:
                if (selectedAccount != -1) {
                    accounts[selectedAccount].put_data();
                } else {
                    cout << "No account selected. Please select an account first." << endl;
                }
                break;

            case 2:
                if (accountCount < 3) {
                    accounts[accountCount].get_data();
                    accountCount++;
                } else {
                    cout << "Account limit reached. Cannot add more accounts." << endl;
                }
                break;

            case 3: {
                cout << "Select an account by account number: ";
                int accNumber;
                cin >> accNumber;
                int found = 0;

                for (int i = 0; i < accountCount; i++) {
                    if (accounts[i].get_account_number() == accNumber) {
                        selectedAccount = i;
                        found = 1;
                        cout << "Account selected successfully!" << endl;
                        break;
                    }
                }

                if (found == 0) {
                    cout << "Account not found. Please try again." << endl;
                }
                break;
            }

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);

    cout << "24CE108_VIVEK_SANGANI" << endl;
    return 0;
}
