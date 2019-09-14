//File name: DiseaseOutbreakSimulation.cpp
//Author: Sophia Boisvert
//Email Address: SophiaBoisvert@my.unt.edu
//Assignment number: 2
/*Description: The purpose of this program is to 
simulate a disease outbreak and determine how many days the outbreak lasted and the 
infected, susceptible, and recoverd on those days*/
//Last changed: 14/09/2019

#include <iostream>
using namespace std;

int main()
{
	int days; //the variable that will store what day we are on and the final length of the outbreak
	int people; //total number of people in the simulation
	int Si; //number of people susceptible on day i
	int Si_1; //number of people susceptible on day i-1
	int Ii; // number of infected people on day i
	int Ii_1; //number of infected people on day i-1
	int Ri; //number of recovered people on day i
	int Ri_1; //nubmer of people recovered on day i-1
	int B; //contact rate
	int y; //recovery rate

	
	cout << "Enter the total number of people (total number > 0) :";
	cin >> people;
	
	//check to see if the entered number is acceptable. If not, re-prompt the user until an acceptable number is inputted
	while(people <= 0) 
		{
			cout << "\nThe number you entered was less than or equal to zero. Please enter another number greater than 0." 				<< endl;
			cout << "Enter the total number of people (total number > 0) :";
			cin >> people;
		}

	
	cout << "Enter the intial number of infected people (total number of people > intial number infected > 0) :";
	cin >> Ii;	

	//check to see if the entered number is acceptable. If not, re-prompt the user until an acceptable number is inputted
	while((Ii <= 0) || (Ii > people))
		{
			cout << "\nThe number you entered was less than or equal to zero or greater than the total number of people. 				Please enter another number greater than 0 and less than the number of people." << endl;
			cout << "Enter the intial number of infected people (total number of people > intial number infected > 0) :";
			cin >> Ii;
		}	

	cout << "Enter the total number of people in the simulation (1 > infection rate > 0) :";
	cin >> B;

	//check to see if the entered number is acceptable. If not, re-prompt the user until an acceptable number is inputted
	while((B < 0) || (B > 1) 
		{
			cout << "\nThe number you entered was not greater than zero and less than 1. Please enter another number greater 			than 0 and less than 1." << endl;
			cout << "Enter the infection rate (1 > infection rate > 0) :";
			cin >> B;
		}

	cout << "Enter the total number of people in the simulation (1 > recovery rate > 0) :";
	cin >> y;

	//check to see if the entered number is acceptable. If not, re-prompt the user until an acceptable number is inputted
	while((y < 0) || (y > 1)
		{
			cout << "\nThe number you entered was not greater than zero and less than 1. Please enter another number greater 			 than 0 and less than 1." << endl;
			cout << "Enter the recovery rate (1 > recovery rate > 0) :";
			cin >> y;
		}

	Ri = 0; //set recovered people to zero
	Si = people - Ii; //calculate susceptible indivuals
	
	// set Si_1, Ii_1, Ri_1 to their respective next day values
	Si_1 = Si; 
	Ii_1 = Ii;
	Ri_1 = Ri;

	day = 1;

	//run calculation for the days
	while (Ii > 0)
		{
			//Calculate the susceptible
			Si = Si_1 - B * Ii_1 * Si_1;

			//Calculate the infected
			Ii = Ii_1 + B * Ii_1 * Si_1 - y * Ii_1;
			
			//Calculate the recovered
			Ri = Ri_1 + y * Ii_1;
			
			//Print out the data from the day
			cout << "\nDay " << day << " Susceptible: " << Si << " Infected: " << Ii << " Recovered: " << Ri;
			
			// set Si_1, Ii_1, Ri_1 to their respective next day values
			Si_1 = Si; 
			Ii_1 = Ii;
			Ri_1 = Ri;
			day++;
		}

	//Print out the the total days of the outbreak
	cout << "\nThe outbreak lasted " << day << " days.";

	return 0;
}
