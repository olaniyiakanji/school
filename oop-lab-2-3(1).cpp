#include <iostream>
using namespace std;
int main()
{
	int a;
	int b;
	char opr;
	int addition;
	int subtraction; 
	
	 cout<<"Enter the first number: ";
	 cin>> a;
	  cout<<endl;
	 
	 cout<<"Enter the second number: ";
	 cin>> b;
	cout<<endl;
	
	cout<<"Enter an operator (+ or -): ";
	 cin>> opr;
	cout<<endl;
	
	if(opr == '+')
	{
		addition = a + b;
		cout<<"Sum = "<<addition<<endl;
	}
	
	else if(opr == '-')
	{
		 subtraction = a - b;
		 cout<<"Dif = "<<subtraction<<endl;
	}
	else
	{
		cout<<"Invalid";
	}
		return 0;
}

