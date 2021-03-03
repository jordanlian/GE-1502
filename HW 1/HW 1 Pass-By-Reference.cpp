// HW #1 Pass-by-Reference

/* Jordan Lian, GE 1502, Whalen 10:30 - 11:35, 308 Hurtig Hall 

This program demos the use of call by reference by calling a function 
called quadratic_formula to find the roots of a quadratic function when applied to the equation ax^2 + bx + c = 0

User will input coefficients a, b, and c, and the function will calculate the 2 roots

If the discriminant is negative and the roots are imaginary, the user will be informed of that 

*/

//library files
#include <cmath> //square root function, power function (if necessary)
#include <iostream> //cin cout
using namespace std;

//repeat of function prototype
void quadratic_formula(double a, double b, double c, double& r1, double& r2, double& d); 
//3 pass-by values, 3 pass-by-reference, lower case letter variables

int main(void)
{   //this function must be repeatable
	int i = 1; //variable that determines whether to repeat the program or not
	int b = 1; //test number, initialized to 1
	
	do //execute at least once, so must use do while loop
	{
		//declare local variables
		double A, B, C, root_1, root_2, discriminant; //capital letters for main function
	
		//get user input
		cout << "Test " << b << endl;
		cout << "Please enter the three coefficients 'a', 'b', and 'c' for the quadratic equation 0 = ax^2 + bx + c --> ";
		cin >> A >> B >> C;
	
		//call function to find area and volume
		quadratic_formula(A, B, C, root_1, root_2, discriminant); //No need to include 'double' or '&'. Use main function variables.
		
		//show output to user
		
		if (discriminant >= 0)
		{
			cout << "\nThe first root is " << root_1;
			cout << "\nThe second root is " << root_2 << endl;
			
			if (root_1 == root_2) //perfect square trinomial
				cout << "This equation is a perfect square trinomial" << endl;
		}
		else //discriminant is less than 0
			cout << "\nThe roots are imaginary\n";

		cout << "\nPlease enter 1 to quit, enter 2 to keep testing --> ";
		cin >> i;
		cout << endl << "--------------------------------------\n\n";
		b++; //new test number (applied if user continues testing)	
	} while(i == 2);
	
	system("pause");
	return 0;
} //end of main

//start sub-function
void quadratic_formula(double a, double b, double c, double& r1, double& r2, double& d) //watch for potential variable mismatching
{ 
	r1 = (-b + sqrt(b*b - 4*a*c)) / (2*a); 
	r2 = (-b - sqrt(b*b - 4*a*c)) / (2*a);
	d = (b*b) - (4*a*c);
} //end of sub-function

