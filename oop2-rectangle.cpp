//Write a class called "Rectangle" that has private member variables for its width and height, 
//and public member functions for setting and getting those values, 
//as well as a function for calculating the rectangle's area.
#include <iostream>
using namespace std;
class Rectangle
{
	//private members declaration
	private: //they have to be under the private keyword
		int width;
		int height;
	//declaring the public member functions	
	public: 
	
	void setWidth(int w)
	{
		width = w;
	}
	int getWidth()const
	{
		return width;
	}
	
	void setHeight(int h)
	{
		height = h;
	}
	int getHeight()const
	{
		return height;
	}
	//Function to calculate and return the area of the rectangle
	int CalArea()const
	{
		return width * height;
	}
	
};

int main()
{
	Rectangle rect; //creating object of class i.e. rect. rect is the object of class Rectangle
	
	//use rect to set the width and height values
	rect.setWidth(5);
	rect.setHeight(10);
	
	//print the width and the height and the area of the rectangle
	cout<<"Width = "<<rect.getWidth()<<endl;
	cout<<"Height = "<<rect.getHeight()<<endl;
	cout<<"Area = "<<rect.CalArea()<<endl;
	
	return 0;
}


