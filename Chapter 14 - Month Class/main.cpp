#include <iostream>
#include "Month.h"

using namespace std;

int main() 
{
	//Setup
	Month date;			//The date to be changed and demonstrated
	Month duplicate;	//The duplicate to show order of operation
	date.setMonth(4);
	
	//Increment demonstration
	duplicate = date++;
	cout << "The original is incremented, but the copy happens before this is changed\n";
	cout << date.getName() << " this is month number " << date.getMonth() << ".\n";
	cout << duplicate.getName() << " this is month number " << duplicate.getMonth() << ".\n";

	duplicate = ++date;
	cout << "\nThe original is incremented, but the copy is made after this iteration\n";
	cout << date.getName() << " this is month number " << date.getMonth() << ".\n";
	cout << duplicate.getName() << " this is month number " << duplicate.getMonth() << ".\n";

	//Decrement demonstration
	duplicate = date--;
	cout << "\nThe original is decremented, the copy is not\nThis time with the overloaded << operator\n";
	cout << date << "\n";
	cout << duplicate << "\n";

	duplicate = --date;
	cout << "\nThe original is decremented, the copy is too\n";
	cout << date << "\n";
	cout << duplicate << "\n";

	//Demonstration of overloaded >> operator
	cout << "\nPlease select a new month\n";
	cin >> date;
	cout << date;

	cout << "\n\nA program by Spencer Curtis\n";

	return 1;
}