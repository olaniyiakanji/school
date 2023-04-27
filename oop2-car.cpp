//Create a class called "Car" that has private member variables for its make, model, and year, 
//and public member functions for setting and getting those values. 
//Also include a function for starting the car and a function for stopping the car.
#include <iostream>
using namespace std;
class Car
{
	private:
		string make;
		string model;
		int year;
		bool isTheEngineRunning;
	public:
		//intialise constructor
	Car(string carMake, string m, int y )
	{
		make = carMake;
		model = m;
		year = y;		
	}
	void setMake(string carMake)
	{
		make = carMake;
	}
	string getMake()
	{
		return make;
	}
	
	void setModel(string m)
	{
		model = m;
	}
	string getModel()
	{
		return model;
	}
	
	void setYear(int y)
	{
		year = y;
	}
	int getYear()
	{
		return year;
	}
	//Also include a function for starting the car and a function for stopping the car.
	void start()
	{
		isTheEngineRunning = true;
		cout<<"The car has started and the engine is running"<<endl;
	}
	void stop()
	{
		isTheEngineRunning = false;
		cout<<"The car has stoped and the engine is not running"<<endl;
		
	}	
};
int main()
{
	Car myCar("Toyota", "Corolla", 2000);
	//Car myCar;
	myCar.setMake("Honda");
	myCar.setModel("Civic");
	myCar.setYear(2020);
	myCar.start();	
	
	//print the width and the height and the area of the rectangle
	cout<<"Make = "<<myCar.getMake()<<endl;
	cout<<"Model = "<<myCar.getModel()<<endl;
	cout<<"Year = "<<myCar.getYear()<<endl;
	
	myCar.stop();
	
	return 0;
}
//Write a class called "BankAccount" that has private member variables for its account number, 
//balance, and owner's name, and public member functions for setting and getting those values, 
//as well as functions for depositing and withdrawing money from the account.


