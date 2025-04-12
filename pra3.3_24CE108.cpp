#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Account {
private:
    int accountNumber;
    string accountHolderName;
    double balance;

public:
    Account(int accNumber, const string& name, double initialBalance)
        : accountNumber(accNumber), accountHolderName(name), balance(initialBalance) {}

    int getAccountNumber() const { return accountNumber; }
    string getAccountHolderName() const { return accountHolderName; }
    double getBalance() const { return balance; }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited " << amount << " to account " << accountNumber
                 << ". New balance: " << balance << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrew " << amount << " from account " << accountNumber
                 << ". New balance: " << balance << endl;
        } else {
            cout << "Invalid withdrawal amount or insufficient balance." << endl;
        }
    }

    void transfer(Account& toAccount, double amount) {
        if (amount > 0 && amount <= balance) {
            withdraw(amount);
            toAccount.deposit(amount);
            cout << "Transferred " << amount << " from account " << accountNumber
                 << " to account " << toAccount.accountNumber << "." << endl;
        } else {
            cout << "Transfer failed due to insufficient funds or invalid amount." << endl;
        }
    }
};

class Bank {
private:
    vector<Account> accounts;
    int accountCount;

public:
    Bank() : accountCount(0) {}

    void createAccount() {
        string name;
        double initialBalance;
        int accountNumber = ++accountCount;

        cout << "Enter account holder's name: ";
        getline(cin >> ws, name);
        cout << "Enter initial balance: ";
        cin >> initialBalance;

        accounts.emplace_back(accountNumber, name, initialBalance);
        cout << "Account created successfully. Account Number: " << accountNumber << endl;
    }

    Account* findAccount(int accountNumber) {
        for (auto& account : accounts) {
            if (account.getAccountNumber() == accountNumber) {
                return &account;
            }
        }
        cout << "Account not found." << endl;
        return nullptr;
    }

    void displayAccounts() {
        if (accounts.empty()) {
            cout << "No accounts to display." << endl;
            return;
        }

        cout << "Account Number | Account Holder Name | Balance" << endl;
        for (const auto& account : accounts) {
            cout << account.getAccountNumber() << " | "
                 << account.getAccountHolderName() << " | "
                 << account.getBalance() << endl;
        }
    }

    int getTotalAccounts() const {
        return accounts.size();
    }
};

int main() {
    Bank myBank;
    int choice;

    while (true) {
        cout << endl;
        cout << "Banking System Menu:" << endl;
        cout << "1. Create Account" << endl;
        cout << "2. Display Accounts" << endl;
        cout << "3. Deposit" << endl;
        cout << "4. Withdraw" << endl;
        cout << "5. Transfer" << endl;
        cout << "6. View Total Accounts" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                myBank.createAccount();
                break;
            }
            case 2: {
                myBank.displayAccounts();
                break;
            }
            case 3: {
                int accNum;
                double amt;
                cout << "Enter account number: ";
                cin >> accNum;
                cout << "Enter deposit amount: ";
                cin >> amt;
                if (Account* acc = myBank.findAccount(accNum)) acc->deposit(amt);
                break;
            }
            case 4: {
                int accNum;
                double amt;
                cout << "Enter account number: ";
                cin >> accNum;
                cout << "Enter withdrawal amount: ";
                cin >> amt;
                if (Account* acc = myBank.findAccount(accNum)) acc->withdraw(amt);
                break;
            }
            case 5: {
                int fromAcc, toAcc;
                double amt;
                cout << "Enter source account number: ";
                cin >> fromAcc;
                cout << "Enter destination account number: ";
                cin >> toAcc;
                cout << "Enter transfer amount: ";
                cin >> amt;
                Account* from = myBank.findAccount(fromAcc);
                Account* to = myBank.findAccount(toAcc);
                if (from && to) from->transfer(*to, amt);
                break;
            }
            case 6: {
                cout << "Total accounts: " << myBank.getTotalAccounts() << endl;
                break;
            }
            case 7: {
                cout << "Exiting program..." << endl;
                cout << "24CE108_VIVEK_SANGANI" << endl;
                return 0;
            }
            default:
                cout << "Invalid choice." << endl;
        }
    }
}
