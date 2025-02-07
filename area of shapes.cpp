#include<stdio.h>
#include<conio.h>
#include<iostream>
using namespace std;

class shapes
{
	public:
		
		
	void Carea()
	{
		float r;
		cout<<"Enter the radius:";
		cin>>r;
		cout<<"Area of Circle:"<<(3.14*r*r);
	}
	void Rarea()
	{
		float l1,l2;
		cout<<"Enter the length:";
			cin>>l1;
		cout<<"Enter the breadth:";
			cin>>l2;
		cout<<"Area of rectangle:"<<(l1*l2);
	}
	void Sarea()
	{
		float s;
		cout<<"Enter the side:";
			cin>>s;
		cout<<"Area of Square is:"<<(s*s);
	}
	void Tarea()
	{
		float b,h;
		cout<<"Enter the base:";
			cin>>b;
		cout<<"Enter the height:";
			cin>>h;
		cout<<"Area of triangle:"<<(0.5*b*h);
	}
		
		 
};
int main()
{
	shapes area;
	int choice;
	cout<<"_________# AREA #____________"<<endl;
	cout<<"1)Circle  \n2)Rectangle  \n3)Square    \n4)Triangle  \n";
	cout<<"CHOICE:";
		cin>>choice;
	
	
	if(choice==1){
	area.Carea();	
	}
	else if(choice==2){
		area.Rarea();
	}
	else if(choice==3){
		area.Sarea();
	}
	else if(choice==4){
		area.Tarea();
	}
	else{
		cout<<"WRONG CHOICE!!!!!!!!!!!";
	}
}
