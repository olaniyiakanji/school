//Write a program that uses a while loop to prompt the user to enter a password, 
//and then keeps prompting them until they enter the correct password.
#include <iostream>
using namespace std;

int main()
{
	string pass = "password";
	string input;
	
	cout<<"Enter password:";
	
	while(input != pass)
	{
		cin>>input;
		
		if(input == pass)
		{
			cout<<"Access granted";
			break;
		}
		else
		{
			cout<<"Incorrect password! Try again:";
		}
	}
	
	return 0;
}
