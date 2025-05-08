#include <iostream>
#include <string>

using namespace std;

const int MAX_TRANSACTIONS = 100;

class BankAccount {
private:
    string accountHolder;
    double balance;
    string transactionHistory[MAX_TRANSACTIONS];
    int transactionCount;

    void logTransaction(const string &log) {
        if (transactionCount < MAX_TRANSACTIONS) {
            transactionHistory[transactionCount++] = log;
        } else {
            cout << "Transaction log full. Cannot log further." << endl;
        }
    }

public:
    BankAccount(string name, double initialBalance) {
        accountHolder = name;
        balance = initialBalance;
        transactionCount = 0;
        logTransaction("Account created with balance " + to_string(balance));
    }

    void deposit(double amount) {
        if (amount <= 0) {
            logTransaction("Error in deposit: Invalid amount " + to_string(amount));
            cout << "Deposit failed: Amount must be positive." << endl;
            return;
        }
        balance += amount;
        logTransaction("Deposited " + to_string(amount) + ", Balance: " + to_string(balance));
        cout << "Deposit successful! New balance: " << balance << endl;
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            logTransaction("Error in withdraw: Invalid amount " + to_string(amount));
            cout << "Withdrawal failed: Amount must be positive." << endl;
            return;
        }
        if (amount > balance) {
            logTransaction("Error in withdraw: Insufficient balance for " + to_string(amount));
            cout << "Withdrawal failed: Insufficient balance. Current balance: " << balance << endl;
            return;
        }
        balance -= amount;
        logTransaction("Withdrew " + to_string(amount) + ", Balance: " + to_string(balance));
        cout << "Withdrawal successful! New balance: " << balance << endl;
    }

    void displayTransactionHistory() {
        cout << endl << "Transaction History for " << accountHolder << ":" << endl;
        if (transactionCount == 0) {
            cout << "No transactions recorded." << endl;
        } else {
            for (int i = 0; i < transactionCount; ++i) {
                cout << transactionHistory[i] << endl;
            }
        }
    }
};

int main() {
    string name;
    double initialBalance;
    double amount;
    int choice;

    cout << "Enter account holder's name: ";
    cin >> name;
    cout << "Enter initial deposit: ";
    cin >> initialBalance;

    BankAccount account(name, initialBalance);

    do {
        cout << endl << "Bank Menu:" << endl;
        cout << "1. Deposit" << endl;
        cout << "2. Withdraw" << endl;
        cout << "3. Transaction History" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter deposit amount: ";
                cin >> amount;
                account.deposit(amount);
                break;
            case 2:
                cout << "Enter withdrawal amount: ";
                cin >> amount;
                account.withdraw(amount);
                break;
            case 3:
                account.displayTransactionHistory();
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 4);

    cout << endl << "24CE108_VIVEK_SANGANI" << endl;
    return 0;
}
