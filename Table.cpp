#include<stdio.h>
#include<conio.h>
#include<iostream>

using namespace std;

class numbers{
	public:

	void Table(int n)
	{
		int i;
		for(i=1;i<=10;i++){
			cout<<endl;
			cout<<n<<"x"<<i<<"="<<n*i<<endl;
		}
	}
};


int main()
{
	numbers num;
	int a;
	cout<<"enter number : ";
	cin>>a;

	num.Table(a);
}
