#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>

using namespace std;

//declare subfunction
void rate_of_change(double h, double r, double density, double TL, double T, double c, double &ROC);

int main(void)
{
	//declare variables
	double pi;
	double TI, TL, h, density, c , time_step, change_in_temperature;
	double As, volume, m, T, ROC, r, r_increment;
	double time = 0;
	int i, d = 1;

	//output file for results
	ofstream outfile;
	outfile.open("weld_radius_time_50-50.txt"); //60-40 txt file
	
	pi = 4*atan(1); //define pi
	
	//get values from user
	cout << "Enter initial temperature of thermocouple junction (sphere) (C) --> ";
	cin >> TI;
	
	cout << "Enter liquid temperature (C) --> ";
	cin >> TL;
	
	cout << "Enter heat transfer coefficient (W/m^2*C) --> ";
	cin >> h;
	
	cout << "Enter sphere density (kg/m^3) --> ";
	cin >> density;
	
	cout << "Enter sphere specific heat (J / kg * C) --> ";
	cin >> c;
	
	cout << "Enter sphere radius (m) --> ";
	cin >> r;
	
	cout << "Enter desired time step for temperature history (s) --> ";
	cin >> time_step;
		
	T = TI;
	r_increment = 0.00001;
	cout << "\nTime (s) \tWeld Radius(m)\n";
	time = 0;
	
	while(time <= 5) //overall constraint
	{
		//call sub-function, 7 inputs
		rate_of_change(h, r, density, TL, T, c, ROC); //write variables, don't declare types
				
		//formulas
		change_in_temperature = time_step * ROC; 
		T = T + change_in_temperature;
		time = time + time_step;
		
		//once temperature reaches limit, record time and corresponding radius
		if(abs(TL - T) <= 0.1) 
		{
			//print out results
			cout << time << " \t\t " << r << endl;
			outfile << time << " \t\t " << r << endl;
			
			//reset/increment variables
			r = r + r_increment; //increment radius for new cycle
			time = 0; //reset time to 0 for new cycle
			T = TI; //reset temperature
		}
	}
	
	do //execute loop one last time
	{
		//call sub-function, 7 inputs
		rate_of_change(h, r, density, TL, T, c, ROC); //write variables, don't declare types
					
		//formulas
		change_in_temperature = time_step * ROC; 
		T = T + change_in_temperature;
		time = time + time_step;
		
		//logic test to break from loop and finish program
		if(abs(TL - T) <= 0.1) 
		{
			//print out results
			cout << time << " \t\t " << r << endl;
			outfile << time << " \t\t " << r << endl;
			
			//break from loop		
			d = 2;
		}
	} while(d == 1);
	
	cout << endl;
	
	system("pause");
	return 0;
}

//sub-function -- rate of change
void rate_of_change(double h, double r, double density, double TL, double T, double c, double &ROC)
{
	double pi = 4 * atan(1);
	double As = 4*pi*r*r; //surface area
	double volume = pi*r*r*r*(4.0/3.0); //volume
	double m = density * volume;
	
	ROC = (h*As*(TL - T) ) / (m*c);
}

