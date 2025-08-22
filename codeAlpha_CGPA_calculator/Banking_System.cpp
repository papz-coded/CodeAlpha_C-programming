#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Transaction class
class Transaction {
public:
    string type;   // Deposit, Withdraw, Transfer
    double amount;

    Transaction(string t, double a) {
        type = t;
        amount = a;
    }

    void display() {
        cout << type << " : " << amount << endl;
    }
};

// Account class
class Account {
public:
    int accountNumber;
    double balance;
    vector<Transaction> history;

    Account(int accNo, double initialBalance = 0.0) {
        accountNumber = accNo;
        balance = initialBalance;
    }

    void deposit(double amount) {
        balance += amount;
        history.push_back(Transaction("Deposit", amount));
        cout << "Deposited " << amount << ". New Balance = " << balance << endl;
    }

    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient balance!" << endl;
        } else {
            balance -= amount;
            history.push_back(Transaction("Withdraw", amount));
            cout << "Withdrew " << amount << ". New Balance = " << balance << endl;
        }
    }

    void transfer(Account &receiver, double amount) {
        if (amount > balance) {
            cout << "Insufficient balance for transfer!" << endl;
        } else {
            balance -= amount;
            receiver.balance += amount;
            history.push_back(Transaction("Transfer Sent", amount));
            receiver.history.push_back(Transaction("Transfer Received", amount));
            cout << "Transferred " << amount << " to Account " << receiver.accountNumber << endl;
        }
    }

    void showHistory() {
        cout << "\nTransaction History for Account " << accountNumber << ":\n";
        for (auto &t : history) {
            t.display();
        }
    }

    void displayInfo() {
        cout << "\nAccount Number: " << accountNumber
             << "\nBalance: " << balance << endl;
    }
};

// Customer class
class Customer {
public:
    string name;
    Account account;

    Customer(string n, int accNo, double balance = 0.0) : account(accNo, balance) {
        name = n;
    }

    void displayCustomerInfo() {
        cout << "\nCustomer Name: " << name << endl;
        account.displayInfo();
    }
};

// Main Function
int main() {
    // Create Customers with accounts
    Customer c1("Alice", 101, 5000);
    Customer c2("Bob", 102, 3000);

    // Display initial info
    c1.displayCustomerInfo();
    c2.displayCustomerInfo();

    // Perform transactions
    c1.account.deposit(1000);
    c1.account.withdraw(2000);
    c1.account.transfer(c2.account, 1500);

    // Show transaction histories
    c1.account.showHistory();
    c2.account.showHistory();

    // Final account info
    c1.account.displayInfo();
    c2.account.displayInfo();

    return 0;
}