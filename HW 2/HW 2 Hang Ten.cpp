/* Jordan Lian, 1/25/2018, GE 1502, HW 2, Let's hang ten

This program reads in a txt file full of data and gets the wave steepness for each set of data.
It will calculate the average wave steepness and then find which sets of data exceeds the average.

*/

#include <iostream>
#include <fstream> //read from txt file
using namespace std;
#include <iomanip> //decimal place, set precision function

#define MAX 1000 //test up to 100 chars

int main(void)
{
	//local variables
	int year[MAX], month[MAX], day[MAX], hour[MAX], minute[MAX], waves; //int arrays
	double wave_height[MAX], wave_length[MAX], wave_steepness[MAX]; //double arrays
	int i=0, b=0; //counter for while loop, number of waves exceeding the average
	double average_wave_steepness, sum=0, perc; //average, total sum of wave steepness values, percentage
	
	//reading the txt file
	string filename = "waves.txt";
	cout << "Please enter file name to read the table from --> ";
	cin >> filename; //save user input as string
	
	//input file variables
	ifstream infile;
	infile.open(filename.c_str());
	
	//test to see if file exists
	if(!infile)
	{
		cout << "\nCan't find the file - terminating program\n";
		return 0; //end program
	}
	
	//reading file
	cout << endl;
	cout << "Year     Month      Day       Hour      Minute       Wave Height      Wave Length       Calculated Wave Steepness" << endl << endl;
		while ( infile >> year[i] >> month[i] >> day[i] >> hour[i] >> minute[i] >> wave_height[i] >> wave_length[i] )
		{
			//formula for wave steepness
			wave_steepness[i] = (1.0 * wave_height[i] / wave_length[i]); 
			
			cout << setprecision(2) << fixed; //set to 2 fixed decimal places
			cout << year[i] << "       " << month[i] << "         " << day[i] << "         " << hour[i] << "         " << 
			minute[i] << "            " << wave_height[i] << "             " << wave_length[i] << "                  " << wave_steepness[i] 
			<< "        " << endl;
			
			//sum of the wave steepness values for average
			sum += wave_steepness[i]; 
			i++; //go through arrays		
		} //end while loop
	
		//average wave steepness calculations
		waves = i; //total waves
		average_wave_steepness = sum/waves; 
		
		//counting wave steepness values greater than the average wave steepness
		for(i=0; i < waves; i++)
		{
			if (wave_steepness[i] > average_wave_steepness) 
				b++; //number of waves greater than the average
		} //end for loop
	
	//percentage of wave steepness values greater than the average
	perc = (1.0 * b / waves) * 100; //turn int values into a double 
	
	//print output
	cout << "\nThere are " << waves << " total values. The sum of those values is equal to " << sum << endl;
	cout << perc << "% of the values exceed the average wave steepness of " << average_wave_steepness << endl; 
	cout << "In total, " << b << " of the values exceeds the average wave steepness" << endl << endl; //number of values exceeding the average

	system("pause");
	return 0;
} //end of main 

