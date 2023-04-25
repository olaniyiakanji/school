/*
Question: Write a C++ program to calculate the volume of a cube, sphere, and cylinder. Define

three functions with the same name "calculateVolume", but each taking a different number and

type of arguments to calculate the volume for the respective shapes.

For example, the first "calculateVolume" function should take a single argument representing the

side length of the cube. The second "calculateVolume" function should take a single argument

representing the radius of the sphere. The third "calculateVolume" function should take two

arguments representing the radius and height of the cylinder.

Your program should prompt the user to enter the dimensions for each shape and call the

appropriate function to calculate its volume.
*/
#include <iostream>
#include <cmath>
using namespace std;

double calculateVolume(double length)// this is about the cube
{
	//return length * length * length;
	return pow(length, 3);
}

double calculateVolume1(double radius)// this is about the sphere
{
	return (4.0/3.0) * M_PI * pow(radius, 3);
}
double calculateVolume(double radius, double height)//this is about the cylinder
{
	return M_PI * pow(radius, 2) * height;
}
 
int main()
{
	int choice;
	cout<<"Enter 1 for volume of cube\nEnter 2 for volume of Sphere\nEnter 3 for volume of Cylider"<<endl;
	cin>>choice; 
	switch (choice)
	{
		case 1:
		 double l;
		 cout<<"Enter the length of the cube";
		 cin>>l;
		 cout<<"The volume of the cube is = "<<	calculateVolume(l)<<endl;
		 break;
		 
		 case 2:
		 double r;
		 cout<<"Enter the length of the sphere";
		 cin>>r;
		 cout<<"The volume of the cube is = "<<	calculateVolume1(r)<<endl;
		 break;
		 
		case 3:
		 double ra;
		 double h;
		 cout<<"Enter the radius of the Cylinder";
		 cin>>ra;
		 cout<<"Enter the higth of the Cylinder";
		 cin>>h;
		 cout<<"The volume of the cylinder is = "<<	calculateVolume(ra,h)<<endl;
		 break;
		 
		 default:
		 	cout<<"Ivalid choice";
		 	break;
	}
	return 0; 
}
