/* Jordan Lian, GE 1502, HW 3 - That's Deep!

This program will read a text file containing many ocean depth measurements in a 6 meter x 6 meter area.
The program will call two functions using call by reference to find the deepest 
point in the ocean, and the deepest two by two area.
//read in array, use nested for loop

*/ 

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

#define MAX 6

double deepest_point(double ocean[MAX][MAX]);
double two_by_two(double ocean[MAX][MAX], int& f, int& g);

int main(void)
{
	//declare variables	
	string filename = "depth.txt";
	double ocean_depth[MAX][MAX];
	int i=0, j=0, f, g; //initialized variable for matrix array
	int row, column;
	double start, big;
	
	//read file
	cout << "The file depth.txt will read a 6x6 matrix of ocean depth values in a 6x6 area (meters squared). Please enter depth.txt to import --> ";
	cin >> filename;
	
	ifstream infile;
	infile.open(filename.c_str());
	
	ofstream outfile;
	outfile.open("ocean_depth.txt");
	
	if(!infile)
	{
		cout << "You selected the wrong file. The program will terminate." << endl;
		return 0;
	}
	
	//reading txt file
	cout << endl;
	for(i=0; i < MAX; i++)
	{
		for(j=0; j < MAX; j++)
		{
			infile >> ocean_depth[i][j];
			cout << ocean_depth[i][j] << " ";
			outfile << ocean_depth[i][j] << " ";	
		}
		cout << endl;
		outfile << endl;
	}
	
	//deepest point
	start =	deepest_point(ocean_depth);
	cout << "\nThe deepest point is " << start << " meters" << endl;
	outfile << "The deepest point is " << start << " meters" << endl;	
	
	big = two_by_two(ocean_depth, f, g); //sub-function
	cout << "The deepest 2x2 area in meters squared is " << big << " bounded by rows " << f+1 << " and " << f+2 << " with columns " 
	<< g+1 << " and " << g+2 << endl << endl;
	
	outfile << "The deepest 2x2 area in meters squared is " << big << " bounded by rows " << f+1 << " and " << f+2 << " with columns " 
	<< g+1 << " and " << g+2 << endl << endl;
	
	system("pause");
	return 0;
}

double deepest_point(double ocean[MAX][MAX])
{
	double start=0;
	int a, b;
	
	for(a=0; a < MAX; a++)
	{
		for(b=0; b < MAX; b++)
		{
			if(ocean[a][b] > start)
				start = ocean[a][b];
		}
	}
	return start;
}

double two_by_two(double ocean[MAX][MAX], int& f, int& g) 
{
	int d, e;
	double big = 0;
	double sum, avg;
	for(d=0; d < (MAX-1); d++)
	{
		for(e=0; e < (MAX-1); e++)
		{	
			sum = ocean[d][e] + ocean[d+1][e] + ocean[d][e+1] + ocean[d+1][e+1];
			avg = sum / 4.0;
			if (avg > big)
			{
				big = avg;
				f = d;
				g = e;
			}
		}				
	}	
	return big;
}

