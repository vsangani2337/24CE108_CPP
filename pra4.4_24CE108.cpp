#include <iostream>
#include <string>
#include <stack>
using namespace std;

// Base Class for Bank Account
class BankAccount {
protected:
    string accountNumber;
    double balance;

public:
    BankAccount(string accNum, double initialBalance)
        : accountNumber(accNum), balance(initialBalance) {}

    virtual ~BankAccount() {
        cout << "BankAccount Destructor called!" << endl;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: $" << amount << "\nNew balance: $" << balance << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    virtual bool withdraw(double amount) = 0;

    double getBalance() const {
        return balance;
    }

    string getAccountNumber() const {
        return accountNumber;
    }
};

// Derived Class for Savings Account
class SavingsAccount : public BankAccount {
private:
    double interestRate;

public:
    SavingsAccount(string accNum, double initialBalance, double rate)
        : BankAccount(accNum, initialBalance), interestRate(rate) {}

    ~SavingsAccount() {
        cout << "SavingsAccount Destructor called!" << endl;
    }

    bool withdraw(double amount) override {
        if (amount > balance) {
            cout << "Insufficient funds!" << endl;
            return false;
        }
        balance -= amount;
        cout << "Withdrew: $" << amount << "\nNew balance: $" << balance << endl;
        return true;
    }

    void applyInterest() {
        balance += balance * (interestRate / 100);
        cout << "Interest applied. New balance: $" << balance << endl;
    }
};

// Derived Class for Current Account
class CurrentAccount : public BankAccount {
private:
    double overdraftLimit;

public:
    CurrentAccount(string accNum, double initialBalance, double limit)
        : BankAccount(accNum, initialBalance), overdraftLimit(limit) {}

    ~CurrentAccount() {
        cout << "CurrentAccount Destructor called!" << endl;
    }

    bool withdraw(double amount) override {
        if (amount > balance + overdraftLimit) {
            cout << "Overdraft limit exceeded!" << endl;
            return false;
        }
        balance -= amount;
        cout << "Withdrew: $" << amount << "\nNew balance: $" << balance << endl;
        return true;
    }
};

// Transaction History Using STL
class TransactionHistory {
private:
    stack<string> transactions;

public:
    void addTransaction(const string& t) {
        transactions.push(t);
    }

    void undoLastTransaction() {
        if (!transactions.empty()) {
            cout << "Undoing transaction: " << transactions.top() << endl;
            transactions.pop();
        } else {
            cout << "No transactions to undo." << endl;
        }
    }
};

// Main Function
int main() {
    string accountType, accountNumber;
    double initialBalance, interestRate, overdraftLimit;
    int transactionChoice;
    bool running = true;

    cout << "Enter account type (Savings/Current): ";
    cin >> accountType;

    cout << "Enter account number: ";
    cin >> accountNumber;

    cout << "Enter initial balance: $";
    cin >> initialBalance;

    TransactionHistory history;

    if (accountType == "Savings" || accountType == "savings") {
        cout << "Enter interest rate (%): ";
        cin >> interestRate;

        SavingsAccount account(accountNumber, initialBalance, interestRate);

        while (running) {
            cout << "\nChoose an operation:\n";
            cout << "1. Deposit\n2. Withdraw\n3. Apply Interest\n4. Undo Last Transaction\n5. Exit\n";
            cout << "Enter your choice: ";
            cin >> transactionChoice;

            switch (transactionChoice) {
                case 1: {
                    double amount;
                    cout << "Enter deposit amount: $";
                    cin >> amount;
                    account.deposit(amount);
                    history.addTransaction("Deposited $" + to_string(amount));
                    break;
                }
                case 2: {
                    double amount;
                    cout << "Enter withdrawal amount: $";
                    cin >> amount;
                    if (account.withdraw(amount))
                        history.addTransaction("Withdrew $" + to_string(amount));
                    break;
                }
                case 3:
                    account.applyInterest();
                    history.addTransaction("Applied interest");
                    break;
                case 4:
                    history.undoLastTransaction();
                    break;
                case 5:
                    running = false;
                    break;
                default:
                    cout << "Invalid choice!" << endl;
            }
        }
    } else if (accountType == "Current" || accountType == "current") {
        cout << "Enter overdraft limit: $";
        cin >> overdraftLimit;

        CurrentAccount account(accountNumber, initialBalance, overdraftLimit);

        while (running) {
            cout << "\nChoose an operation:\n";
            cout << "1. Deposit\n2. Withdraw\n3. Undo Last Transaction\n4. Exit\n";
            cout << "Enter your choice: ";
            cin >> transactionChoice;

            switch (transactionChoice) {
                case 1: {
                    double amount;
                    cout << "Enter deposit amount: $";
                    cin >> amount;
                    account.deposit(amount);
                    history.addTransaction("Deposited $" + to_string(amount));
                    break;
                }
                case 2: {
                    double amount;
                    cout << "Enter withdrawal amount: $";
                    cin >> amount;
                    if (account.withdraw(amount))
                        history.addTransaction("Withdrew $" + to_string(amount));
                    break;
                }
                case 3:
                    history.undoLastTransaction();
                    break;
                case 4:
                    running = false;
                    break;
                default:
                    cout << "Invalid choice!" << endl;
            }
        }
    } else {
        cout << "Invalid account type!" << endl;
    }

    cout << "24CE108_VIVEK_SANGANI" << endl;

    return 0;
}
