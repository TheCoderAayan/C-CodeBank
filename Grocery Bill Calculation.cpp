#include <iostream>
#include <iomanip>
using namespace std;

int main() 
{
    int n;
    cout << "Enter the number of products: ";
    cin >> n;
	int a[n];
	string name[n];
	int prices[n];
	int total = 0;

    cout << "Enter the name and price of each product:" << endl;
    for (int i = 0; i < n; i++) 
	{
        cin >> name[i];
        cin >> prices[i];
        total = total + prices[i];
    }


    cout << "---------------------------------------------------------" << endl;

    for (int i = 0; i < n; i++) 
	{
        cout << setw(5) << name[i] << "." << setw(5)<<prices[i] << endl;
    }

    cout << "---------------------------------------------------------" << endl;
    cout << "Total bill: " << total << endl;

    return 0;
}

