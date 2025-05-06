#include <iostream>
#include <string>
using namespace std;

class Bank {
public:
    void deposit(int amount) {
        cout << "Depositing ?" << amount << " in cash." << endl;
    }

    void deposit(float amount) {
        cout << "Depositing ?" << amount << " via digital payment." << endl;
    }

    void deposit(int amount, string upi) {
        cout << "Depositing ?" << amount << " using UPI (" << upi << ")." << endl;
    }
};

class Account {
private:
    int acc_num;
    int balance;

public:
    void show_accDetails() {
        cout << "Account Number: " << acc_num << ", Balance: ?" << balance << endl;
    }

    Account operator+(int amount) {
        return Account(acc_num, balance + amount);
    }

    Account operator-(int amount) {
        return Account(acc_num, balance - amount);
    }

    Account(int acn, int bal) {
        acc_num = acn;
        balance = bal;
    }

    int getBalance() {
        return balance;
    }
};

int main() {
    Bank b1;
    b1.deposit(5000);
    b1.deposit(1500.75f);
    b1.deposit(2500, "gpay@upi");

    cout << "-----------------------------------------------------------" << endl;

    Account a1(1, 10000);
    Account a2(2, 5000);

    a1.show_accDetails();
    a2.show_accDetails();

    a1 = a1 - 3000;
    a2 = a2 + 3000;

    cout << "New Account 1 Balance: ?" << a1.getBalance() << endl;
    cout << "New Account 2 Balance: ?" << a2.getBalance() << endl;

    a1 = a1 - 2000;
    cout << "Remaining Balance: ?" << a1.getBalance() << endl;

    return 0;
}

