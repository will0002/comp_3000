//Name: Will Parker
//Auburn UserID: wpp0002
//filename: hw2.ccp
//Development Environment: vim,g++,Linux 
//Compile: g++ -o hw2 hw2.cpp 
//Sample usage: ./hw2

#include <iostream> //We need this for cin and cout


using namespace std;

int main () 
{ 
	
	const double RATE = .001;//percent of coke that is made up of sweetener
	double weightOfMouse, sweetenerKillMouse, weightOfMan;//defines fractional variables
	int  numOfCokes;//defines whole number variable
	//Instructions for the function 
	cout << endl << "What is the amount of artificial sweetener needed to kill a mouse: ";//Prompt the user to enter the amount of sweetener
        cin >> sweetenerKillMouse;
	cout << endl << "What is the weight of the mouse: ";//Prompt the user to enter the weith of the mouse
	cin >> weightOfMouse;
	cout << endl << "What is the weight of the dieter: ";//Prompt the user to enter their goal weight
	cin >> weightOfMan;
	cout << endl;
	
	numOfCokes = sweetenerKillMouse * weightOfMan / weightOfMouse / RATE; //calculates the number of cokes that can be drunk without dying
	//because numOfCokes is int type, the outcome will automatically be rounded down

	cout << "You can drink " << numOfCokes << " diet sodas without dying as a result." << endl;
	
	return 0; 
 }

//     
