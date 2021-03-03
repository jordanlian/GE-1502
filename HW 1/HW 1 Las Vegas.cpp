// HW #1 Take me to Las Vegas!

/* Jordan Lian, GE 1502, Whalen 10:30 - 11:35, 308 Hurtig Hall 

This program demos the game of craps. The player will pick the number of games that he/she wants to play (limit of 5-20, strictly enforced).
He/she will also pick the amount of money to wager per game. He/she will start with $1000.
The game will terminate if the bank balance is in jeopardy. The bet cannot be more than $1000.
At the end of the game, the player will be informed of his final balance (net gain or net loss?).

*/

//library files
#include <iostream> //input output
#include <cstdlib> //cstandard library - srand() rand()
#include <ctime> //time
#include <fstream> //.txt files
using namespace std;

//repeat of function prototype
void rolling_function(int& first_roll, int& second_roll, int& total, int& p); //4 pass-by-reference

//global file pointer 
ofstream outfile;

int main (void)
{
	//random time function
	srand(time(0));

	//local variables
	int games, i, a, bet, decision; 
	int money = 1000; //initialize starting bank balance
	int	roll_1, roll_2, sum, point; //sub-function variables, different names, corresponding order
	
	//file to write to
	outfile.open("Las_Vegas.txt");

	//intro to program
	cout << "Welcome!\nThis program stimulates the dice game called craps. \nIt will simulate the rolling of the dice at the table.";
	cout << "\nYou will need to request how many games you would like to play.";
	cout << "\nHope you have lots of fun!";
	cout << "\nWarning: If you enter an invalid bet or number of games twice, you will be disqualified." << endl;

	//enter amount to bet
	cout << "\nFirst please enter the amount of money you would like to wager in US Dollars. You have $1000 to begin with. --> ";
	cin >> bet;
	
	//if bet is greater than $1000, enter new amount
	if (bet > 1000) 
	{
		cout << "You don't have enough money to bet $" << bet;
		cout << "\nPlease enter a different amount of money to wager. --> ";
		cin >> bet;	
	}
	
	//enter number of games user wants to play
	cout << "\nNow please enter the number of games you would like to play (5-20 games) --> ";
	cin >> games;

	if ( (games > 20) || (games < 5) ) //if you enter a number not within 5-20 games
	{
		cout << "\nThe number of games you would like to play (" << games << ") is not within the appropriate range.";
		cout << "\nPlease enter the number of games you would instead like to play (5-20 games please) --> ";
		cin >> games;
	}
	
	if ( (games <= 20) && (games >= 5) && (1000 >= bet) ) //play the game if the conditions are met
	{ // for loop takes place
		cout << "\nYou have chosen to play " << games << " games\n";
		outfile << "You have chosen to play " << games << " games\n";
		
		for(i=0; (i < games); i++) 
		{
			cout << "\n--------------- Starting a new round -- Game " << i+1 << " ---------------"; //makes program easier to read
			outfile << "\n--------------- Starting a new round -- Game " << i+1 << " ---------------"; //makes program easier to read
				
			//call back sub-function values
			rolling_function(roll_1, roll_2, sum, point); //corresponding order of variables from sub-function
				
			cout << "\n\nYour first roll is " << roll_1; //first roll
			cout << "\nYour second roll is " << roll_2; //second roll
			cout << "\nThe sum of your two rolls is " << sum; //sum
			cout << "\n";
			point = sum; 
			
			outfile << "\n\nYour first roll is " << roll_1; 
			outfile << "\nYour second roll is " << roll_2; 
			outfile << "\nThe sum of your two rolls is " << sum; 
			outfile << "\n";
						
			if (sum == 7 || sum == 11) //if sum = 7 or 11, you win
			{
				cout << "\nYou win, you are special" << endl;
				outfile << "\nYou win, you are special" << endl;
				a = 1;
				money = money + bet;
				cout << "Your current balance is $" << money << endl;
				outfile << "Your current balance is $" << money << endl;
			}
			else if (sum == 2 || sum == 3 || sum == 12) //if sum is 2, 3, or 12, you lose
			{
				cout << "\nYOU LOSE HAHAHAHAHAH, you just got 'craps'" << endl;
				outfile << "\nYOU LOSE HAHAHAHAHAH, you just got 'craps'" << endl;
				a = 1;
				money = money - bet;
				cout << "Your current balance is $" << money << endl;
				outfile << "Your current balance is $" << money << endl;
			}
			else //if the sum is not any of those numbers, you have to make the point
			{
				cout << "The point to make is " << point << endl;
				outfile << "The point to make is " << point << endl;
				a = 2; //go to while loop
			}
		
			while (a == 2) //if you have a "point to make"
			{
				rolling_function(roll_1, roll_2, sum, point); //use sub-function again
				cout << "\nYour new first roll is " << roll_1; 
				cout << "\nYour new second roll is " << roll_2; 
				cout << "\nThe sum of your two new rolls is " << sum << endl;
				
				outfile << "\nYour new first roll is " << roll_1; 
				outfile << "\nYour new second roll is " << roll_2; 
				outfile << "\nThe sum of your two new rolls is " << sum << endl;
			
				if (sum == point) //you win the game
				{
					cout << "\nYou just made your point. You win. You are special.\n";
					outfile << "\nYou just made your point. You win. You are special.\n";
					a = 1;
					money = money + bet; //current balance calculation
					cout << "Your current balance is $" << money << endl;
					outfile << "Your current balance is $" << money << endl;
				}
				else if (sum == 7) //you lose the game
				{
					cout << "\nYOU LOSE HAHAHAHAHAH, you just got 'craps'" << endl;
					outfile << "\nYOU LOSE HAHAHAHAHAH, you just got 'craps'" << endl;
					a = 1;
					money = money - bet; //current balance calculation
					cout << "Your current balance is $" << money << endl;
					outfile << "Your current balance is $" << money << endl;
				}
				else //try again until you make the point (unless the sum is 7)
				{
					cout << "Oops, try again\n";
					outfile << "Oops, try again\n";
					a = 2;
				}
			} //end of while loop
			
			if (money < 0) //you don't have any more left in the bank
			{
				cout << "\nYou have a negative bank balance. You now owe the bank interest." << endl;
				cout << "\nYou cannot continue by NEU Policy due to your irresponsible actions." << endl;
				
				outfile << "\nYou have a negative bank balance. You now owe the bank interest." << endl;
				outfile << "\nYou cannot continue by NEU Policy due to your irresponsible actions." << endl;
				
				break; //break from loop
			}
			else if (money == 0)
			{
				cout << "\nYou have no money left in the bank.";
				cout << "It is recommended that you stop before you lose more money and you owe the bank. \n\nWould you like to stop playing?";
				cout << "\nEnter 1 for Yes and 2 for No --> ";
				cin >> decision;
				
				outfile << "\nYou have no money left in the bank.";
				outfile << "It is recommended that you stop before you lose money and you owe the bank. \n\nWould you like to stop playing?";
				outfile << "\nEnter 1 for Yes and 2 for No" << endl;
				
				if (decision == 1)
				{
					outfile << "\nYou have chosen to quit\n";
					break; //break from loop	
				}	
				else if (decision == 2)
				{
					outfile << "\nYou have chosen to keep playing despite the recommendations.\n";
				}
			}
			else if (bet > money) //your potential losses will go to a number below 0, ex. balance is $200, bet is $800
			{	
				cout << "\nYour bet of $" << bet << " is greater than your current balance of $" << money << ".\n";
				cout << "It is recommended that you stop before you lose money and you owe the bank. \n\nWould you like to stop playing?";
				cout << "\nEnter 1 for Yes and 2 for No --> ";
				cin >> decision;
				
				outfile << "\nYour bet of $" << bet << " is greater than your current balance of $" << money << ".\n";
				outfile << "It is recommended that you stop playing before you lose more money and you owe the bank.";
				
				if (decision == 1)
				{
					outfile << "\nYou have chosen to quit\n";
					break; //break from loop	
				}	
				else if (decision == 2)
				{
					outfile << "\nYou have chosen to keep playing despite the recommendations.\n";
				}
			}
		} //end of the for loop
		
		//game over, summarize earnings/losses
		cout << "\n------------------------------------------------------";
		cout << "\n\nIt looks like you have completed your games!";
		
		outfile << "\n------------------------------------------------------";
		outfile << "\n\nIt looks like you have completed your games!";
		
		if (money > 1000) //profit
		{	
			cout << "\nYou have made a profit of $" << money - 1000;
			outfile << "\nYou have made a profit of $" << money - 1000;
		}
		else if (money < 1000) //loss
		{
			cout << "\nHAHAHAHA, you have a net loss of $" << 1000 - money;
			outfile << "\nHAHAHAHA, you have a net loss of $" << 1000 - money;			
		}
		else if (money = 1000) //break even
		{
			cout << "\nYou have no net gain or net loss in money today.";
			outfile << "\nYou have no net gain or net loss in money today.";
		}
		
		//final conclusion
		cout << "\n\n--------------- That's it for today. Thank you for your participation :) ---------------\n\n"; //summary line
		outfile << "\n\n--------------- That's it for today. Thank you for your participation :) ---------------\n\n"; //summary line
	} //end of the if statement			
	else if ( ( (games > 20) || (games < 5) ) || (money < bet) ) //invalid number of games or invalid bet (entered twice)
	{
		cout << "\nYou either have entered an invalid number of games twice today,";
		cout << "\nor you have entered an invalid amount of money to bet twice today.";
		cout << "\nAs a result, you are not permitted to play. ";
		cout << "\nPlease try again in the future.\n" << endl;
		
		outfile << "You either have entered an invalid number of games twice today,";
		outfile << "\nor you have entered an invalid amount of money to bet twice today.";
		outfile << "\nAs a result, you have been disqualified and you are therefore not permitted to play. ";
		outfile << "\nPlease try again in the future.";
	} //end of else if statement

	system("pause");
	return 0;
}

//start sub-function
void rolling_function(int& first_roll, int& second_roll, int& total, int& P) //sub-function for returning rolled dice values
{
	first_roll = rand() %6 + 1; //do mod 6 + 1 for the dice program
	second_roll = rand() %6 + 1; 
	total = first_roll + second_roll; //sum
}

