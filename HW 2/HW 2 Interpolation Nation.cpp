/* Jordan Lian, 1/25/2018, GE 1502, HW 2, Interpolation Nation

This program will solve a linear interpolation problem using arrays
The function given is a chart of flight path angle versus the coefficient of lift

*/

#include <iostream>
#include <fstream> //read from txt file
#include <cstdlib> 
#include <iomanip>
using namespace std;

//constant
#define MAX 15

int order_check(double array_input[], int num_points); //return 1 or 0 for true or false

int main(void)
{
	//local variables
	double FPA[MAX], COL[MAX]; //arrays from txt file
	double slope, FPA_inp, COL_out; //slope calculation variables	
	int i=0, j=0, a=0, order; //for loop variables
	int num_points;
	
	cout << "The table should compare the flight path angle (FPA) versus the coefficient of lift (COL)" << endl;
	cout << "Once uploaded, you may enter FPA value within the appropriate range of the table to find the corresponding COL value" 
	<< endl << endl;
	
	//reading the txt file
	string filename = "FPA_COL.txt";
	cout << "Please enter file name to read the table from --> ";
	cin >> filename; //save user input as string
	
	//input file variables
	ifstream infile;
	infile.open(filename.c_str());
	
	//test to see if file exists
	if(!infile)
	{
		cout << "\nCan't find the file - terminating program\n";
		return 0;	//end program
	}
	
	//intro
	cout << "\nFPA (Degrees)" << "       COL" << endl;
	
	//reading file
	while (infile >> FPA[i] >> COL[i]) 
	{
		cout << "   " << FPA[i] <<"               "<< COL[i] <<endl;
		i++;
	}
	
	//checking order of points -- make sure it's in ascending order
	num_points = i;
	order = order_check(FPA,num_points);
	if(order == 0)
	{
		cout<< "Data is not in ascending order. Exiting...";
		exit(0);
	}
	
	//entering FPA and more
	while(a == 0)
	{
		cout << "------------------------------------------------------------\nNow please enter the flight path angle in degrees --> ";
		cin >> FPA_inp; //store value(s) in array
	
		if( (FPA_inp > 17) || (FPA_inp < 0) )
		{
			cout << "The value you entered is not valid within the table range. The program will terminate." << endl;
			break;
		}	
	
		//print output
		while(FPA_inp > FPA[j])
		{
			j++;
		}
		
		//calculations
		slope = (FPA[j] - FPA[j-1]) / (COL[j] - COL[j-1]); //slope formula
		COL_out = ( (FPA_inp - FPA[j-1]) / slope ) + COL[j-1]; //recalculated COL value
		
		cout << setprecision(3) << fixed;	
		cout << "\nFor a flight path angle of " << FPA_inp << " degrees, the coefficient of lift is " << COL_out << endl;
		cout << "The point for this coordinate is (" << COL_out << ", " << FPA_inp << ")" << endl;
	
		cout << "\nThe 2 data points used were (" << COL[j-1] << ", " << FPA[j-1] << ")";
		cout << " and (" << COL[j] << ", " << FPA[j] << ")" << endl;;
		
		cout << "The slope of the two points is " << slope << endl;
	
		//stay in program or quit
		cout << "\nPlease enter 0 to test more values, enter 1 to quit --> ";
		cin >> a;
		
		if(a == 1)
			break; //break from while loop
			
	} //end of big while loop
	
	cout << endl;
	system("pause");
	return 0;
} //end of main

//sub-function
 
int order_check(double array_input[], int num_points)
{
	for(int i=1; i < num_points; i++)
	{
	   if(array_input[i] < array_input[i-1])	
	   		return 0;
	}
	return 1;	
} //end of sub-function 

