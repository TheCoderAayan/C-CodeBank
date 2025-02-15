#include <iostream>
#include <string>
using namespace std;

class BankAccount {
    
private:
    string accountHolder;
    int accountNumber;
    string accountType;
    double balance;

public:
    //Default Constructor
    BankAccount() 
    {
        accountHolder="Unknown";
        accountNumber=0;
        accountType="NULL";
        balance=0.0;
    }

    // Parameterized Constructor
    BankAccount(string holder, int number, string type, double initialBalance)
    {
        accountHolder=holder;
        accountNumber=number;
        accountType=type;
        balance=initialBalance;
    }

    // Accessor Methods
    string getAccountHolder() const { 
        return accountHolder; 
    }
    int getAccountNumber() const { return accountNumber; }
    string getAccountType() const { return accountType; }
    double getBalance() const { return balance; }

    // Mutator Method
    void setAccountType(string newType) { accountType = newType; }

    // Deposit Money
    void deposit(int accNum, double amount) {
        cout << "-------------------------------------" << endl;
        if (accNum == accountNumber) {
            if (amount > 0) {
                balance += amount;
                cout << "Deposited " << amount << "...\nNew Balance: " << balance << endl;
            } else {
                cout << "Invalid deposit amount!" << endl;
            }
        } else {
            cout << "Invalid account number!" << endl;
        }
        cout << "-------------------------------------" << endl;
    }

    // Withdraw Money
    void withdraw(int accNum, double amount) {
        cout << "-------------------------------------" << endl;
        if (accNum == accountNumber) {
            if (amount > 0 && amount <= balance) {
                balance -= amount;
                cout << "Withdrew " << amount << "...\nNew Balance: " << balance << endl;
            } else {
                cout << "Insufficient balance or invalid amount!" << endl;
            }
        } else {
            cout << "Invalid account number!" << endl;
        }
        cout << "-------------------------------------" << endl;
    }

    // Display Account Details
    void displayAccountDetails(int accNum) const {
        cout << "-------------------------------------" << endl;
        if (accNum == accountNumber) {
            cout << "Account Details:" << endl;
            cout << "Holder: " << accountHolder << endl;
            cout << "Account Number: " << accountNumber << endl;
            cout << "Type: " << accountType << endl;
            cout << "Balance: " << balance << endl;
        } else {
            cout << "Invalid account number!" << endl;
        }
        cout << "-------------------------------------" << endl;
    }
    
    // Set New Account
    void setNewAccount() {
        cout << "-------------------------------------" << endl;
        cin.ignore(); // To handle newline character
        cout << "Enter Account Holder Name: ";
        getline(cin, accountHolder);
        cout << "Enter Account Number: ";
        cin >> accountNumber;
        cout << "Enter Account Type (Savings/Current): ";
        cin >> accountType;
        cout << "Enter Initial Balance: ";
        cin >> balance;
        cout << "Account Successfully Created!" << endl;
        cout << "-------------------------------------" << endl;
    }
};

int main() {
    // Creating menu
    BankAccount b;
    int choice, accNum;
    double amount;
    string newType;
    
    do {
    	cout << "-------------------------------------" << endl;
		cout << "   !!!!! XYZ BANK !!!!!  " << endl;
        cout << "-------------------------------------" << endl;
        cout << "1. Set New Account.\n2. Deposit.\n3. Withdraw.\n4. Change Account Type.\n5. Display Account Details.\n6. Exit!!!\n";
        cout << "-------------------------------------" << endl;
        cout << "Enter your choice:";
        cin >> choice;
        cout << "-------------------------------------" << endl;
        
        switch(choice) {
            case 1:
                b.setNewAccount();
                break;
            case 2:
                cout << "Enter account number: ";
                cin >> accNum;
                cout << "Enter amount to deposit: ";
                cin >> amount;
                b.deposit(accNum, amount);
                break;
            case 3:
                cout << "Enter account number: ";
                cin >> accNum;
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                b.withdraw(accNum, amount);
                break;
            case 4:
                cout << "Enter account number: ";
                cin >> accNum;
                cout << "Enter new account type: ";
                cin >> newType;
                if (accNum == b.getAccountNumber()) {
                    b.setAccountType(newType);
                    cout << "Updated account type to " << newType << endl;
                } else {
                    cout << "Invalid account number!" << endl;
                }
                break;
            case 5:
                cout << "Enter account number: ";
                cin >> accNum;
                b.displayAccountDetails(accNum);
                break;
            case 6:
                cout << "-------------------------------------" << endl;
                cout << "Thanks for visiting" << endl;
                cout << "-------------------------------------" << endl;
                break;
            default:
                cout << "-------------------------------------" << endl;
                cout << "Wrong choice" << endl;
                cout << "-------------------------------------" << endl;
                break;
        }
    } while(choice != 6);
    
    return 0;
}

