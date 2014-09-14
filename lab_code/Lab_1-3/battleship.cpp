// Battleship
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// Reset the random number generator with the system clock.
void seed()
   {
       srand(time(NULL));
   }

// Ship class for location and sunk
class Ship
	{
		private:
			int x;
			int y;
			bool sunk;
		public:
			Ship(){
				x = 0;
				y = 0;
				sunk = 0;
			}

			//set
			void setx(int new_x){
				x = new_x;
			}
			void sety(int new_y){
				y = new_y;
			}
			void setsunk(bool is_sunk){
				sunk = is_sunk;
			}

			// get
			int getx(){
				return x;
			}
			int gety(){
				return y;
			}
			bool getsunk(){
				return sunk;
			}
	};

// operation function
int operation(int boardsize, int fleetsize,Ship myshiparray[])
	{
		int x_input;
		int y_input;
		int sunkships = 0;

		// get x and y values
		while(true)
		{
			cout << "Enter your guess, by entering two values for an x and y coordinate." << endl;
			cin >> x_input >> y_input;

			x_input--;
			y_input--;

			if (x_input > (boardsize - 1) || x_input < 0 || (y_input > 
			boardsize - 1) || y_input < 0)
			{
				cout << endl <<"		OUT OF BOUNDS!!!" << endl;
			}
			else
			{
				break;
			}
		}

		// check if guess hit any ships
		for(int i = 0; i < fleetsize; i++){
			if(myshiparray[i].getx() == x_input && 
			myshiparray[i].gety() == y_input){
				myshiparray[i].setsunk(1);
				sunkships++;
			}
		}

		// check if all ships are sunk
		if(sunkships == 1)
		{
			cout << endl <<"		You sunk my boat!!! " << endl 
			<< endl;
			return 1;
			}
		else
		{
			cout << endl <<"		You missed, boo!!! " << endl 
			<< endl;
			return 0;
		}
	}


int main()
{
	// ensure random numbers
	seed();


	// initialize board and fleet size
	cout<< endl <<" 		WELCOME TO BATTLESHIP" << endl << endl;

	int boardsize;
	while (true){
		cout << " How vast are your oceans? Input board size in integer value : " << endl;
		 
		cin >> boardsize;

		if (boardsize < 1)
			cout << " THE BOARD IS TO SMALL!!!" << endl;
		else
			break;
	}


	int fleetsize;
	while (true){
		cout << " How many ships are in your fleet? Input fleet size in integer value : " << endl;
		cin >> fleetsize;

		if(fleetsize > ((boardsize*boardsize) / 2))
			cout<<" Too many ships!!! The maximum enemy fleet allowed is (boardsize^2)/2" << endl;
		else if(fleetsize < 1)
			cout<<"There are no enemy ships!!! Enter more ships"
			 << endl;
		else
			break;
	}

	cout<<"		LET THE BATTLE BEGIN! " << endl;

	// initialize enemy fleet
	Ship myshiparray[fleetsize];

	// check for stacking and assign locations
	for(int i = 0; i < fleetsize; i++){
		int x_value = rand() % boardsize;
		int y_value = rand() % boardsize;

		for(int j = 0; j < i; j++){
			if(myshiparray[j].getx() == x_value && 
			myshiparray[j].gety() == y_value)
			{
				x_value = rand() % boardsize;
				y_value = rand() % boardsize;
				j = 0; // resets to check again
			}
		}
		
		myshiparray[i].setx(x_value);
		myshiparray[i].sety(y_value);
	}
	
	/*
	cout << myshiparray[0].getx() << myshiparray[1].getx()
	 << myshiparray[2].getx() << myshiparray[3].getx()
	  << myshiparray[4].getx() << myshiparray[5].getx()
	   << myshiparray[6].getx() << myshiparray[7].getx()
	    //<< myshiparray[8].gety()
	     << endl;

	cout << myshiparray[0].gety() << myshiparray[1].gety()
	 << myshiparray[2].gety() << myshiparray[3].gety()
	  << myshiparray[4].gety() << myshiparray[5].gety()
	   << myshiparray[6].gety() << myshiparray[7].gety()
	    //<< myshiparray[8].gety()
	     << endl;
	*/
	
	// pause game
	// cin.get();

	// run game
	int shipdestroyed = 0;
	int sunkship = 0;
	int guesscount = 1;
	while (true){

		// run ops
		sunkship = operation(boardsize, fleetsize, myshiparray);
		
		/*	shows how many boats are sunk
		cout << myshiparray[0].getsunk() << myshiparray[1].getsunk()
		 << myshiparray[2].getsunk() << myshiparray[3].getsunk()
		  << myshiparray[4].getsunk() << endl;	
		*/
		
		// add a sunk ship
		if (sunkship == 1)
			shipdestroyed++;

		// end game
		if (shipdestroyed == fleetsize){
			cout<<"CONGRATULATION YOU HAVE DESTROYED THE ENEMY FLEET!"
			<< endl;
			 cout << endl;
			cout<<"It took "<<guesscount<<" shells to destroy the enemy fleet"
			<< endl;
			break;
		}
		
		// how many shells needed to sink the ship
		guesscount++;
	}
}
