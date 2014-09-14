/* Chris Woamck
 * Assignment 1
 * Dr. Hoenigman
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

typedef struct msgarr{
	string type;
	bool sell;
	int price;
} msgarr;

void printArr(msgarr msgbrd[],int *arr_len, int *op_count){
	for(int i = 0; i < (*arr_len); i++){
		(*op_count)++;
		if(msgbrd[i].type != "asdf"){
			(*op_count)++;
			cout << msgbrd[i].type << " " << msgbrd[i].sell << " "
			 << msgbrd[i].price << endl;
			 (*op_count)++;
		}
	}
}

void convert(string x[], msgarr *var, int *op_count){
		
	// set type
	(*var).type  = x[0];
	(*op_count)++;
	
	// set price
	stringstream s_str(x[2]);		// convert to stringstream 
	s_str >> (*var).price;			// use strstream to convert to int
	(*op_count)++;
	
	// set for sale or wanted
	size_t found = 0;					// return type of str.find
	found = x[1].find_first_of('f'); 	// find f
	if(found == 1){
		(*var).sell = true;
	}else{
		(*var).sell = false;
	}
	(*op_count)++;
}

void compare(msgarr msgbrd[], msgarr *var, int *rm_line, int *arr_len, int *hit, bool *des, int *op_count){
	
	(*des) = false;
	(*hit) = false;
	
	// compare to other values in array
	for(int a = 0; a < (*arr_len); a++){
		(*op_count)++;
		
		// comparison algorithm
		// compare type
		if(msgbrd[a].type == (*var).type && msgbrd[a].sell != (*var).sell){
			(*des) = msgbrd[a].sell;		// designate which is for sale
			(*op_count)++;
			
			if((*des) == true){
				(*op_count)++;
				// compare price :: msg for sale : var want
				if(msgbrd[a].price <= (*var).price) {
					(*rm_line) = a;
					(*hit) = 1;
				}else{
					(*hit) = 0;
				}
				(*op_count)++;
				
			}else{
				// compare price :: msg want : var for sale
				if(msgbrd[a].price >= (*var).price){
					(*rm_line) = a;
					(*hit) = 1;
				}else{
					(*hit) = 0;
				}
			}	(*op_count)++;
		
		if((*hit) == true){
			break;
		}
		}
		(*op_count)++;
	}
}

void placeDelete(msgarr msgbrd[], int *hit, msgarr *var, int *arr_len, int *rm_line, int *op_count){
	
	// if it is a hit then shift the array left starting at rm_line
	if((*hit) == 1){
		for(int b = (*rm_line); b < (*arr_len)-1; b++){
			(*op_count)++;
			msgbrd[b].type = msgbrd[b+1].type;
			(*op_count)++;
			msgbrd[b].sell = msgbrd[b+1].sell;
			(*op_count)++;
			msgbrd[b].price = msgbrd[b+1].price;
			(*op_count)++;
		}
	// else place in the msgboard
	}else{
		for(int d = 0; d < (*arr_len); d++){
			(*op_count)++;
			if(msgbrd[d].price == 0){
				msgbrd[d].type = (*var).type;
				(*op_count)++;
				msgbrd[d].sell = (*var).sell;
				(*op_count)++;
				msgbrd[d].price = (*var).price;
				(*op_count)++;
				break;
			}
		}
	}
}

int main()
{
	// variables
	int i = 0;
	int hit = 0;
	int rm_line = 0;
	int arr_len = 109;
	int op_count = 0;
	
	bool des = false;
	
	string x[3];
	string line;
	string attrib;
	
	msgarr msgbrd[arr_len];
	msgarr var;	
	
	// structs
	// file streams
	ifstream msgboard ("Message_Board.txt");	// open input stream to file
	ofstream transaction ("transaction.txt");	// open output stream to file
	
	// initialize messageboard to null values
	for(int c = 0; c < arr_len; c++){
		op_count++;
		
		msgbrd[c].type = "asdf";
		op_count++;
		msgbrd[c].price = 0;
		op_count++;
		msgbrd[c].sell = 0;
		op_count++;
	}
	
	// pull in each line from text file	
	while(!msgboard.eof()){
		op_count++; // file size can change
		
		// input must be strig stream, output string
		getline(msgboard, line); 

		// break up each line into the three attributes
		istringstream strstr(line); // turns string into string stream
		
		// split the line into the three attributes : string/bool/int
		i = 0;
		while(i < 3){
			getline(strstr, attrib, ',');
			x[i] = attrib;
			i++;
		}
		op_count++;	// only once since it is always the same amount of breaks

		// convert attributes for comparison
		convert(x, &var, &op_count);

		// compare and return a value for transaction
		compare(msgbrd, &var, &rm_line, &arr_len, &hit, &des, &op_count);

		// print transaction to file
		if(hit == true){
			if(des == true){
				transaction << msgbrd[rm_line].type << ", " << msgbrd[rm_line].price << endl;
				op_count++;
			}else{
				transaction << var.type << ", " << var.price << endl;
				op_count++;
			}
		}
		
		// place or delete entry onto message board
		placeDelete(msgbrd, &hit, &var, &arr_len, &rm_line, &op_count);

		hit = 0;
	}
	
	printArr(msgbrd, &arr_len, &op_count);
	cout << endl << "Operations count is " << op_count << "." << endl;
	
	msgboard.close();
	transaction.close();
}
