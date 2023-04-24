//Write a program that uses nested loops to print out a multiplication table from 1 to 10.
#include <iostream>
using namespace std;
int main()
{
	cout<<"Multiplication Table"<<endl;
	 //outer loop
	 for(int i = 1; i <= 10; i++)
	 {
	 	//ineer loop
	 	for(int j = 1; j <= 10; j++)
	 	{
	 		int product =  i * j;
	 		//print the multiplication table
	 		cout<<i<<" * "<<j<<" = "<<product<<"\t";
		 }
		 cout<<endl;
	 }
	return 0;
}

