#include <iostream>
#include<iomanip>
using namespace std;

class Bank
{
public:
    int balance = 0, amount, TCount = 0;
    int amounts[100];
    int balances[100];

    void deposit()
    {
        cout << "Enter the amount to deposit: ";
        cin >> amount;
        if (amount > 0)
        {
            balance += amount;
            amounts[TCount] = amount;
            balances[TCount] = balance;
            TCount++;
              cout << "---------------------------------------------\n";
            cout << "Amount deposited successfully.\nCurrent balance: " << balance << "\n";
              cout << "---------------------------------------------\n";
        }
        else
        {
            cout << "Invalid amount. Try again.\n";
              cout << "---------------------------------------------\n";
        }
    }

    void withdraw()
    {
        cout << "Enter the amount to withdraw: ";
        cin >> amount;
        if (amount > 0 && amount <= balance)
        {
            balance -= amount;
            amounts[TCount] = -amount;
            balances[TCount] = balance;
            TCount++;
              cout << "---------------------------------------------\n";
            cout << "Amount withdrawn successfully.\nCurrent balance: " << balance << "\n";
              cout << "---------------------------------------------\n";
        }
        else if (amount > balance)
        {
        	  cout << "---------------------------------------------\n";
            cout << "Insufficient balance.\n";
              cout << "---------------------------------------------\n";
        }
        else
        {
        	  cout << "---------------------------------------------\n";
            cout << "Invalid amount. Try again.\n";
              cout << "---------------------------------------------\n";
        }
    }

    void printPassbook()
    {
        cout << "\nPassbook Entries (Last 5 Transactions):\n";
        cout << "---------------------------------------------\n";
        cout << setw(8) << left << "No."
             << setw(15) << "Amount"
             << setw(15) << "Balance"
             << "\n";
        cout << "---------------------------------------------\n";

        int start = (TCount > 5) ? TCount - 5 : 0;
        for (int i = start; i < TCount; i++)
        {
            cout << setw(8) << left << (i + 1)
                 << setw(15) << amounts[i]
                 << setw(15) << balances[i]
                 << "\n";
        }
        cout << "---------------------------------------------\n";
    }
};

int main()
{
    int choice;
    Bank bank;

    while (true)
    {
    	cout<<"\t\t\t\t\t  ||__ABCXYZ BANK__||    \n";
        cout << "\n1) Press '1' To Deposit Cash.\n2) Press '2' To Withdraw Cash.\n3) Press '3' To Print Passbook (Last 5 Transactions)\n4) Press '4' To Exit.";
          cout << "\n---------------------------------------------";
		cout << "\nEnter your choice: ";
        cin >> choice;
          cout << "---------------------------------------------\n";

        switch (choice)
        {
        case 1:
            bank.deposit();
            break;
        case 2:
            bank.withdraw();
            break;
        case 3:
            if (bank.TCount == 0)
            {
            	  cout << "---------------------------------------------\n";
                cout << "No transactions available to display.\n";
                  cout << "---------------------------------------------\n";
            }
            else
            {
                bank.printPassbook();
            }
            break;
        case 4:
        	  cout << "---------------------------------------------\n";
            cout << "Exiting the system...\n";
              cout << "---------------------------------------------\n";
            return 0;
        default:
        	  cout << "---------------------------------------------\n";
            cout << "Invalid choice... Try again.\n";
              cout << "---------------------------------------------\n";
        }
    }
}

