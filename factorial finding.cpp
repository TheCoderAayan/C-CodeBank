#include<stdio.h>
#include<conio.h>
#include<iostream>

class factorial
{
	public:
		int f=1;
		
		 int fact(int n1)
		 {
		 	while(n1!=1)
		 	{
		 		f=f*n1;
		 		n1--;
			 }
			 return f;
		 }
		 
//		 int fact(int n1)
//		 {
//		 	if(n1==1)
//		 	{
//		 		return 1;
//			 }
//			 else
//			 {
//			 	return (fact(n1-1)*n1);
//			 }
//		 }
		 
	};
		
		
 int main()
{
	factorial number;
	
			int num1;
			
		 	std::cout<<" Enter number :";
		 	
		 	std::cin>>num1;
		 
		    int answer=number.fact(num1);
		    
		    std::cout<<"\nFactorial is:"<<answer;
		 }
