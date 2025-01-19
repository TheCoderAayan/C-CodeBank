#include<stdio.h>
#include<conio.h>
#include<iostream>

using namespace std;
class numbers{
	public:

	int large(int a,int b,int c)
	{
		int ans;
		
		if(a>b)
		{
			a>c?ans=a:ans=c;
			return ans;
		}
		else
		{
			b>c?ans=b:ans=c;
			return ans;
		}
	}
};

int main(){
	numbers num;
	int x,y,z;
	
	cout<<endl<<"Enter the 1st value ";
	cin>>x;
	cout<<endl<<"Enter the 2nd value ";
	cin>>y;
	cout<<endl<<"Enter the 3rd value ";
	cin>>z;
	
	
	
	int ans=num.large(x,y,z);

	cout<<endl<<"--------------------------------";
	cout<<endl<<"Largest number is : "<<ans;
}
