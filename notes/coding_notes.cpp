// Libraries
#include <iostream>
#include <string>

// Not sure what this does %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%Google
using namespace std;

// class implementation
class Automobile{
	private:	// control how they are being modified
		string make;
		string model;
		string condition;
	public:		// what is public %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%Google
		Automobile(string ma, string mo){	// constructor : malloc
			make  = ma;
			model = mo;
			condition = "new";
			cout<<"calling constructor\n";
		}
		~Automobile(){	// destructor : cleans malloc
			cout<<"calling destructor\n";
		}
		void setCondition(string c){	//setter for variable/method
			condition = c;
		}
		string getCondition(){	// getter for variable/method
			return condition;
		}
};

// structure implementation
struct WeatherData{
	double temp;
	double hum;
	double windvel;
};

int main(){

	// cout<< from iostream.h, write out to terminal
	cout<<"hello world\n";
	
	// Variable Types
	int x = 12;
	cout<<x<<"\n";
	int result = x * 12;
	result = x - 12;
	double x2 = 5.5; // floating point
	if (x2 < 5)
		cout<<"x2 < 5\n"; // one line doesn't need brackets
	else if (x2 > 5)
		cout<<"x2 > 5\n";
	else
		cout<<"x2 = 5\n"; // must be bracketed if it is greater than one line
	
	// Loops
	int counter = 0;
	while (counter <= 5){
		cout<<counter<<"\n"; // cout<<something here<<more stuff here		
		counter++;
	}
	
	// struct implementation
	WeatherData dpl; //set the variable for struct dpl
	dpl.hum = 45;
	dpl.temp = 95;
	dpl.windvel = 15;
	
	cout<<(dpl.hum / dpl.temp)<<"\n";
	
	//class implementation
	Automobile subaru("subaru", "outback"); // variable(make,model) of type string
	cout<<subaru.getCondition()<<"\n";
	subaru.setCondition("old");
	cout<<subaru.getCondition()<<"\n";
	
	int myArray[] = {1,2,3};
	cout<<myArray[1]<<"\n";
}

