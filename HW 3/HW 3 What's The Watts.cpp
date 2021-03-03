/* Jordan Lian, GE 1502, HW 3 - What's the Watts

This program will read in a txt file containing power output values each week and each corresponding day.
The program will print the average power output over the 10 week period. 
The program will also print out the average for each week.
The program will also print out the week and day where the smallest power output occurred.

*/ 

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

#define NROWS 10
#define NCOLS 7

double week_average(double test_array[NROWS][NCOLS], int a, double& total_sum); //power[][], average, test_row

int main(void)
{
	//declare variables	
	string filename = "POWER1.txt";
	double power[NROWS][NCOLS];
	int i=0, j=0, a=0; //initialized variables for counter loops
	double average, total_sum, smallest = 500;
	int x, y; //smallest power output variables
	int user_input; //user input
	
	//getting the txt file
	cout << "The file POWER1.txt will read a matrix of power plant output values. Please enter POWER1.txt to import --> ";
	cin >> filename;
	cout << endl;
	
	ifstream infile;
	infile.open(filename.c_str());
	
	ofstream outfile;
	outfile.open("Watts_Results.txt");
	
	if(!infile)
	{
		cout << "You selected the wrong file. The program will terminate";
		cout << "You selected the wrong file. The program will terminate";		
		return 0;
	}
	
	//reading txt file
	for(i=0; i < NROWS; i++)
	{
		for(j=0; j < NCOLS; j++)
		{
			infile >> power[i][j];
			cout << power[i][j] << " ";
			
			if(power[i][j] < smallest)
			{
				smallest = power[i][j];
				x = i;
				y = j;
			}
		}
		cout << endl; //endline after the entire array is printed
	}
	
	//calculating total sum and average
	total_sum = 0;
	for(a=0; a < NROWS; a++)
	{	
		double average = week_average(power, a, total_sum);
	}
		
	cout << "\nThe smallest power output in Megawatts is " << smallest << " on week " << x+1 << " on day "<< y+1 << endl;
	outfile << "The smallest power output in Megawatts is " << smallest << " on week " << x+1 << " on day "<< y+1 <<endl;
	cout << "The total average is "<< total_sum / 10 << " Megawatts" << endl;
	outfile << "The total average is "<< total_sum / 10 << " Megawatts" << endl;	
	
	//week average
	cout << "\nPlease enter 0 if you want averages of every week or just put in the week you want the average of --> ";
	cin >> user_input;
		
	if(user_input == 0)
	{
		for(a=0; a < NROWS; a++) //print out all weeks
		{	
			double average = week_average(power, a, total_sum);
			cout << endl << "Week " << a+1 << ": Average Power Output in Megawatts: " << average;
			outfile << endl << "Week " << a+1 << ": Average Power Output in Megawatts: " << average; 	 
		}
	}
	else if ( (user_input > 0) && (user_input <= 10) ) //user_input is in the restricted domain, print out desired week
	{
		double average = week_average(power, user_input - 1, total_sum); //replace second variable with user_input-1
		cout << endl << "Week " << user_input << ": Average Power Output in Megawatts: " << average;
		outfile << endl << "Week " << user_input << ": Average Power Output in Megawatts: " << average;  
	}
	else
	{
		cout << "\nYou entered a week not within the domain. This program will terminate..." << endl;
		outfile << "\nYou entered a week not within the domain. This program will terminate..." << endl;
		return 0;
	}

	cout << endl << endl;
	system("pause");
	return 0;
} //end main

double week_average(double test_array[NROWS][NCOLS], int a, double& total_sum) //print out weekly averages
{
	double sum, avg;
	//print out weekly averages
	//sum and average
		
		sum = test_array[a][0] + test_array[a][1] + test_array[a][2] + test_array[a][3] + test_array[a][4] + test_array[a][5] + test_array[a][6];
		avg = sum / 7.0;

		total_sum = total_sum + avg;
		return(avg);
}

