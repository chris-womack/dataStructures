
/*
 * We're using C++ for data structures because the language requires us
 * to pay attention to everything. We can allocate memory and see the
 * memory locations where variables are stored. C++ also uses pointers,
 * which are references to memory locations. In data structures where
 * items are linked together, there is usually a pointer between them.
 * It's easier to understand how these structures work if we can see
 * all the memory stuff, and that stuff is easier to see in C++.
 *
 * The functionality for the language is included with libraries and
 * namespaces. To use the functionality associated with the iostream,
 * we need to include the iostream library. These files are also
 * called header files, or .h files.
 *
*/
#include <iostream>
#include <string>
#include <sstream>

/* All of the standard C++ functionality is included in a namespace
 * called std. To use this functionality, we need to let the program
 * know that we want it included, so you say "using namespace std".
 * There are other namespaces, but we're not going to get into that.
*/
using namespace std;

/* Here is a sample function in C++. It has two parameters, both ints,
 * and it returns an int. The function needs to have a return type, that
 * is the int in front of the name of the function. The parameters also
 * need to have their types specified, that's the word int in front of
 * the variables a and b. The return value of the function is specified
 * by the word return that preceeds the value. In this case, a+b.
 *
 */
int mySum(int a, int b){

	return a+b;
}
/*Another function example. This one takes two double arguments and
 * returns a/b, also as a double.
 */
double myDiv(double a, double b){

	return a/b;
}
/*Another function example. This one takes one double argument and
 * returns a/2, also as a double.
 */
double myHalf(double a){
    a = a/2;
    return a;
}

//create a struct data type. It's like a class, but without methods
struct WeatherData{
    double temperature;
    double humidity;
    double windVelocity;
};

class Automobile{
private:
    string make;
    string model;
    string condition;
public:
    Automobile(string ma, string mo){
        make = ma;
        model = mo;
        condition = "new";
        cout<<"calling constructor\n";
    }
    ~Automobile(){
        cout<<"calling destructor\n";
    }
    //void setCondition(string condition);
    //string getCondition();
    void setCondition(string c){
        condition = c;
    }
    string getCondition(){
        return condition;
    }

};


/*There's the main function. Just like in Java, the program needs a
 * place to start, and that place is called main. Unlike Java,
 * there's no class, no public, no public static void main, and no
 * String args[]. Notice that main is an int, meaning that it does
 * return something. The return of main is usually whether the program
 * executed successfully.
 */

int main(){
	/*One of the nice features of C++ is iostreams, which is how C++
	handles input and output. The language is designed to treat IO as
	a stream of characters, and it's up to the developer to handle those
	characters accordingly. The stream can be to/from a keyboard, a file, a variable,
	and the language is designed to handle these scenarios generically.
	We'll look at some of the IOStream features, but there is much more
	available than what we'll examine here. For a more complete explanation,
	see: http://www.cprogramming.com/tutorial/c++-iostreams.html
	*/
	/*iostream handles io from the console, using the cout and cin commands,
	where cout writes to the console and cin reads from the console */
	cout<<"Hello World";
	/*Add another statement to print*/
	cout<<"\nI'm a C++ program\n";
    int x = 12;

    /*cout is how c++ writes out to the console. Notice the semicolon*/
    cout << "Output sentence\n"; // prints Output sentence on screen
    cout << 120;               // prints number 120 on screen
    cout << "\n";
    cout << x;                 // prints the value of x on screen
    cout << "\n";
    /*Multiple insertion operations (<<) may be chained in a single statement:*/
    cout << "This " << " is a " << "single C++ statement. \n";


    /*cin is how we read input from console*/
    double i;
    cout << "Please enter an integer value: ";
    cin >> i;
    cout << "The value you entered is " << i;
    cout << " and its double is " << i*2 << ".\n";


	/*Variables and data types*/
	/*Just like Python and Java, C++ has variables and those variables
	 * have types. The type of a variable determines
	 * how much space the variable needs in memory. For example, an
	 * integer needs 4 bytes and a double needs 8 bytes.
	 * You need to tell C++ the type of the variable when you declare
	 * it. For example, to declare an integer:*/
	 int a = 5;
	 int b = 6;
	 //And, there are operations on variables, such as *,+,-,/
	 int result = a * b;
	 cout<<result;
	 result = a - b;
	 cout<<"\n";
	 cout<<result;
	 //call the function created below main
	 int c = mySum(a,b);
	 cout<<c<<"\n";
	 /* Control structures: if statements and for and while loops
	  *
	  */
	  if (a < 5){
		  cout<<"a < 5"<<"\n";
	  }else if (a > 5){
		  cout<<"a > 5"<<"\n";
	  }else{
		  cout<<"a = 5"<<"\n";
	  }

    // if (condition) statement1 else statement2
      if (i < 5){
          cout<<"i < 5"<<"\n";
      }else if (i > 5){
          cout<<"i > 5"<<"\n";
      }else{
          cout<<"i = 5"<<"\n";
      }

    // while (expression) statement
    /* C++ has a while loop, just like Java and Python, that will
    execute as long as the looping criteria is true. Here, we define
    a variable called counter and initialize it to 0. As long as the
    value of counter is less than or equal to 5, the while loop code
    between the {} will execute. In this example, a function called
    myHalf is called and returning a value, which is stored in the variable
    called half. The variable called counter is incremented by 1 each time through
    the while loop, which is what keeps the while loop from executing forever.
    */
    double half=i;
    int counter = 0;
    while(counter <= 5)
    {
        half = myHalf(i);
        //output a mix of string literals and variables
        cout << "i = " << i << "and half = " << half << "\n";
        i = half;
        counter++;
    }

    //for (initialization; condition; increase) statement;
    double j;
    cout << "Please enter an integer value: ";
    cin >> j;
    cout << "The value you entered is " << j << "\n";;

    /*strings = character sequences
    By convention, the end of strings represented in character sequences is signaled by a
    special character: the null character, whose literal value can be written as '\0'.
    */

    char foo [20];

    // initialization
    char myword[] = { 'H', 'e', 'l', 'l', 'o', '\0' };
    char myword2[] = "Hello";

    // assigning value to char sequences later (after initialization)
    myword[0] = 'B';
    myword[1] = 'y';
    myword[2] = 'e';
    myword[3] = '\0';

    // string console input and output
    char question[] = "What is your name? ";
    char answer[50];
    cout << question;
    cin >> answer;
    cout << "Hello, " << answer << "\n";

    /* cin extraction always considers spaces (whitespaces, tabs, new-line...) as terminating
    the value being extracted, and thus extracting a string means to always extract a single word,
    not a phrase or an entire sentence.
    getline takes the stream (cin) as first argument and the string variable as second*/
    string mystr;
    cout << "What's your name? ";
    cin.ignore();
    getline (cin, mystr);
    cout << "Hello " << mystr << ".\n";

    /*stringstream: allows a string to be treated as a stream, and thus allowing extraction or
    insertion operations from/to strings in the same way as they are performed on cin and cout.
    This feature is most useful to convert strings to numerical values and vice versa.
    */
    float price=0;
    int quantity=0;

    cout << "Enter price: ";
    getline (cin,mystr);
    stringstream(mystr) >> price;
    cout << "Enter quantity: ";
    getline (cin,mystr);
    stringstream(mystr) >> quantity;
    cout << "Total price: " << price*quantity << endl;


    /*In Java, we also worked with classes and objects, where the class defined all of
    the properties and methods of the object. C++ also uses objects, and another variable
    type we didn't use in Java, called structs. Structs are similar to classes, but they
    don't have any methods, only variables.
    */

    /*There is a struct declared outside of the main function, called WeatherData that
    contains a value for temperature, humidity, and windVelocity. We can create a WeatherData
    variable as follows:
    */
    WeatherData dp1;
    dp1.humidity = 45;
    dp1.temperature = 95;
    dp1.windVelocity = 15;
    /*The type is WeatherData and you can set individual values with the . notation.
    The struct is a simpler data structure than the class. Nothing is private, there are
    no methods, no getters and setters. But, it still provides functionality to group variables
    together into one variable, and what gets put into that variable is the user's design.
    */

    cout<<"humidity:"<<dp1.humidity<<" temp:"<<dp1.temperature<<" wind:"<<dp1.windVelocity<<"\n";

    /*Classes. These are similar to what you saw in Java. The class is defined
    above main and is called Automobile. There are three private variables, and a
    get and set method for the make. There are a few ways to define classes in C++.
    This semester, we will also show how to define a class in a separate file and
    include the class definition in a header file.
    */
    Automobile subaru("subaru", "outback");
    subaru.setCondition("wrecked");
    cout<<"class example "<<subaru.getCondition()<<"\n";
	 /*The C++ tutorial link on Moodle provides a great description of
	  * variable types and declaring variables*/
	/*Since main has a return type, we need to return something. We'll
	 * just return 0 for now*/
	return 0;
}
/*Once the code is typed, you will need to build and run it.
 *
 * Notice that a command printed in the window below this one with:
 * g++ -Wall -o "Lecture1IntroductionToC++" "Lecture1IntroductionToC++.cpp"
 * This command calls the C++ compiler to create the executable from
 * the source code. The .cpp file is the source.
 *
 * More info here: http://pages.cs.wisc.edu/~beechung/ref/gcc-intro.html.
 * Compile file, then link with other library files to create the exe.
 * Discuss common flags.
*/


