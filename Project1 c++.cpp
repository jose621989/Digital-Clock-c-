//header file
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
//Variables for my clock
int hours12, hours24, minutes, seconds;
string ampm;
// fnct to add an 1 hr
void addHour() {
	hours12 = hours12 + 1;
	//after adding set the clock
	if (hours12 >= 12) {
		hours12 = hours12 - 12;
		if (ampm == "AM")
			ampm = "PM";
		else
			ampm = "AM";
	}
}
//adding minute to clock
void addMinute() {
	minutes = minutes + 1;
	if (minutes > 59) {
		minutes = 0;
		addHour();

	}
}
//adding second to clock
void addSecond() {
	seconds = seconds + 1;
	if (seconds > 59) {
		seconds = 0;
		addMinute();
	}
}

//main function
int main() {
	//variables
	int choice = 0;
	//setting the intial clock timing manually
	hours12 = 10;
	minutes = 59;
	seconds = 58;
	ampm = "PM";
	//infinite loop unless user wish to exit
	while (1) {
		//calculating the 24 hours calculation
		if (ampm == "PM") {
			hours24 = hours12 + 12;
			if (hours24 >= 24) {
				hours24 = hours24 - 24;
			}
		}
		else {
			hours24 = hours12;
		}
		//printing the clock
		cout << "****************************\t\t****************************\n";
		cout << "* 12-Hour clock *\t\t* 24-Hour clock *\n";
		cout << "* " << setw(2) << setfill('0') << hours12 << ":" << setw(2) << setfill('0') << minutes << ":" << setw(2) << setfill('0') << seconds << " " << ampm << " *";
		cout << "\t\t* " << setw(2) << setfill('0') << hours24 << ":" << setw(2) << setfill('0') << minutes << ":" << setw(2) << setfill('0') << seconds << " " << " *\n";
		cout << "****************************\t\t****************************\n";
		//printing the option
		cout << "\n\n****************************\n";
		cout << "* 1-Add one hour *\n";
		cout << "* 2-Add one minutes *\n";
		cout << "* 3-Add one second *\n";
		cout << "* 4-Exit program *\n";
		cout << "****************************\n";
		cout << "Choose and option: ";
		cin >> choice;
		//executing based on user choice
		if (choice == 1) {
			//function to add an hour
			addHour();
		}
		else if (choice == 2) {
			//function to add a minute
			addMinute();
		}
		else if (choice == 3) {
			//function to add second
			addSecond();
		}
		else if (choice == 4) {
			//if user wish to exit
			cout << "Exiting program...";
			break;
		}
		else {
			//printing the error message
			cout << "Invalid input. Try Again...";
		}
	}
}

