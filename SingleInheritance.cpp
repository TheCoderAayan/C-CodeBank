#include<iostream>
using namespace std;

class A{

		
	public:
		int a,b;
		void Set()
		{
			cout<<"Enter two numbers:"<<endl;
			cin>>a>>b;
		}
		
};
class B : public A{
	private:
		int c;
	public:
		
		void GetAdd()
		{
			c=a+b;
			cout<<"Addittion is:"<<c;
		}
};
int main()
{
	B obj;
	obj.Set();
	obj.GetAdd();
}
