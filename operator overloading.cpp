#include<iostream>
using namespace std;

class Complex {
	public:
		int real, img;
		
	Complex( int r = 0 , int i = 0)
	{
		real = r;
		img = i;
	}
	Complex operator+ (Complex c4)
	{
		Complex c5;
		c5.real = real + c4.real ;
		c5.img = img + c4.img ;
		return c5;
	}
	
	void disp()
	{
		cout << "Sum : " << real << " + " << img << "i" << endl ;
	}
		
};

int main()
{
	Complex c1(5,3);
	Complex c2(4,2);
	
	Complex c3 = c1 + c2 ;
	c3.disp();
	
	return 0;
}
