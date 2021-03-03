#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>

using namespace std;

//declare subfunction
void rate_of_change(double h, double r, double density, double TL, double T, double c, double &ROC);

int main(void)
{
	double pi;
	double TI, TL, h, density, c, r , time_step, change_in_temperature;
	double As, volume, m, T, ROC;
	double time = 0;
	int i;
	
	ofstream outfile;
	outfile.open("benchmark_plot_60-40.txt");
	
	pi = 4*atan(1);
	
	cout << "Enter initial temperature of thermocouple junction (sphere) (C) --> ";
	cin >> TI;
	
	cout << "Enter liquid temperature (C) --> ";
	cin >> TL;
	
	cout << "Enter heat transfer coefficient (W/m^2*C) --> ";
	cin >> h;
	
	cout << "Enter sphere density (kg/m^3) --> ";
	cin >> density;
	
	cout << "Enter sphere specific heat (J / kg * C)--> ";
	cin >> c;
	
	cout << "Enter sphere radius (m) --> ";
	cin >> r;
	
	cout << "Enter desired time step for temperature history (s) --> ";
	cin >> time_step;
	
	
	//for loop -- time increment
	
	T = TI;
	
	cout << "Time (s) \tTemp (C)\n";

	while( (abs(TL - T) >= 0.1) && (time <= 5) )
	{
		cout << time << " \t\t " << T << endl;
		outfile << time << " \t\t " << T << endl;

		//call sub-function, 7 inputs
		rate_of_change(h, r, density, TL, T, c, ROC); //write variables, don't declare types
		
		//formulas
		change_in_temperature = time_step * ROC; 
		T = T + change_in_temperature;
		time = time + time_step;	
	}

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

