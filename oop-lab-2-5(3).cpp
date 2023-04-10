#include <iostream>
using namespace std;

//method to add the numbers
void add()
{
	cout<<"You are adding"<<endl;
	int a;
	int b;
	cout<<"Enter first number"<<endl;
	cin>>a;
	cout<<"Enter the second number"<<endl;	
	cin>>b;
	
	cout<<a<<" + "<<b<<" = "<< a + b<<endl;
}

//method to subtract the numbers
void sub()
{
	cout<<"You are subtracting"<<endl;
	int a;
	int b;
	cout<<"Enter first number"<<endl;
	cin>>a;
	cout<<"Enter the second number"<<endl;	
	cin>>b;
	
	cout<<a<<" - "<<b<<" = "<< a - b<<endl;	
}
void menu()
{
	int option;
	cout<<"---Enter 1 for addition\n Enter 2 for subtraction\n"<<endl;
	cin>>option; //user's input/option
	if(option == 1)
	{
		add();
	}
	else if(option == 2)
	{
		sub();
	}
	else
	{
		cout<<"Invalid";
	}	
}


int main()
{
	menu();

	return 0;
}
	
