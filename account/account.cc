#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Bank;

class BankAccount{

//private fields 

private:
    string customerName;
    double balance;
    

public:
//Constructor 
    BankAccount(){
        customerName = "";
        balance = 0.0;
    }

    BankAccount(string name, double initialBalance){
        customerName = name;
        balance = initialBalance;
    }
// Extactor methods
    string getCustomerName() const {
        return customerName;
    }

    double getBalance() const {
        return balance;
    }

//Deposit method
    void deposit(double amount){
        if (amount > 0){
            balance += amount;
            cout << "Deposited $" << amount << " into " << customerName << "'s account. New balance: $" << balance << endl;
        }
        else {
            cout << "Invalid deposit amount." << endl;
        }
    }

//withdraw method
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn $" << amount << " from " << customerName << "'s account. New balance: $" << balance << endl;
        } else {
            cout << "Invalid withdrawal amount or insufficient balance." << endl;
        }
    }

    void addInterest(double rate) {
        // Calculate the interest and add it to the balance
        double interest = balance * (rate / 100.0);
        balance += interest;
        cout << "Added interest at a rate of " << rate << "% to " << customerName << "'s account. New balance: $" << balance << endl;
    }

};

class Bank {
private:
    vector<BankAccount> accounts;

public:
    void addAccount(string name, double initialBalance) {
        BankAccount newAccount(name, initialBalance);
        accounts.push_back(newAccount);
    }

    void printAllAccounts() {
        cout << "All Bank Accounts:" << endl;
        for (const BankAccount& account : accounts) {
            cout << "Customer Name: " << account.getCustomerName() << ", Balance: $" << account.getBalance() << endl;
        }
    }

      void depositToAccount(string name, double amount) {
        for (BankAccount& account : accounts) {
            if (account.getCustomerName() == name) {
                account.deposit(amount);
                return;
            }
        }
        cout << "Customer not found." << endl;
    }

    void withdrawFromAccount(string name, double amount) {
        for (BankAccount& account : accounts) {
            if (account.getCustomerName() == name) {
                account.withdraw(amount);
                return;
            }
        }
        cout << "Customer not found." << endl;
    }

    void addInterestToAllAccounts(double rate) {
        for (BankAccount& account : accounts) {
            account.addInterest(rate);
        }
    }
};

int main() {
     Bank bank;

    // Create and add initial accounts to the bank
    bank.addAccount("Juan Doe", 1000.0);
    bank.addAccount("Jane Smith", 500.0);

    // Create bank account objects and test them
    BankAccount account1("Juan Doe", 1000.0);
    BankAccount account2("Jane Smith", 500.0);

    cout << "Initial balances:" << endl;
    cout << account1.getCustomerName() << "'s balance: $" << account1.getBalance() << endl;
    cout << account2.getCustomerName() << "'s balance: $" << account2.getBalance() << endl;

    // Test deposit and withdrawal
    account1.deposit(500.0);
    account2.withdraw(200.0);

    cout << "Updated balances:" << endl;
    cout << account1.getCustomerName() << "'s balance: $" << account1.getBalance() << endl;
    cout << account2.getCustomerName() << "'s balance: $" << account2.getBalance() << endl;

    // Print all bank accounts (initial and created by Bank)
    bank.printAllAccounts();

    // Deposit $200 to John Doe's account
    bank.depositToAccount("Juan Doe", 200.0);

    // Withdraw $100 from Jane Smith's account
    bank.withdrawFromAccount("Jane Smith", 100.0);

    // Add interest to all accounts
    bank.addInterestToAllAccounts(3.5); // 3.5% interest

    // Print all bank accounts after performing operations
    bank.printAllAccounts();
    
    return 0;
}
