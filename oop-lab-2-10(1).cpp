//Write a C++ function to calculate the area of a rectangle.
// The function should take two arguments, width and length, with a default value of 1.0 for both. 
//If the user passes only one argument, it should be used as the length, and the width should default to 1.0.

#include <iostream>
using namespace std;

double calRecArea(double length = 1.0, double width = 2.0)
{
	return width * length; 
}
int main()
{
	double width;
	double length;
	
	cout<< "enter the length";
	cin>> length;
	
	cout<<"enter the width";
	cin>>width;
	
	//function with user defined argument
	cout<<"User defined argument: "<<calRecArea(length, width)<<endl;
	
	//function with default argument
	cout<<"Default argument: "<<calRecArea()<<endl;
	
	//function with user defined argument
	cout<<"User defined argument: "<<calRecArea(length)<<endl;
	
	
	return 0;
}


