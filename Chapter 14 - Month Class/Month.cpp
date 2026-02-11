#include "Month.h"
#include <iostream>

using namespace std;

//I would much rather use a map, but that's not covered yet.
//Not sure why the book ended the months with both '.' and ',' but I choose ','
static string months[12] = { "January,", "Febuary,", "March,", "April,",
					"May,", "June,", "July,", "August,", "September,",
					"October,", "November,", "December," };

//Conversions
int Month::monthToInt(string name)
{
	//Perform a simple linear search to see if its a valid month
	//and if so return its position + 1 as the int. 0 means it wasn't found.
	int i = 0;
	int pos = -1;
	bool found = false;
	while ((!found) && (i < 12))
	{
		if (name == months[i])
		{
			found = true;
			pos = i;
		}
		i++;
	}
	return pos+1;
}

string Month::intToMonth(int monthNumber)
{
	//Pair the monthNumber to its position in the months array and return that.
	return months[monthNumber - 1];
}

//Constructors
//Default constructor
Month::Month()
{
	name = "January,";
	monthNumber = 1;
}

//Constuctor from on month name
Month::Month(string n)
{
	setName(n);
}

//Constructor from month number
Month::Month(int num)
{
	setMonth(num);
}

//Mutators
//Attempts to set a month based on string input
//Likely would have made more sense to overload one setMonth with
//a separate string and int version, but I wanted to adhere to the text
void Month::setName(string n)
{
	//We try to convert the string to the corresponding monthNumber
	//If 0 is returned we have failed, otherwise use the input and number
	int num = monthToInt(n);

	if (num != 0)
	{
		name = n;
		monthNumber = num;
	}
	else
	{
		cout << "Error: Invalid month name.";
		exit(EXIT_FAILURE);
	}
}

//Attempts to set a new month based on number input
void Month::setMonth(int num)
{
	//Make sure the number is within 1-12 before changing the month
	if (num >= 1 && num <= 12)
	{
		name = intToMonth(num);
		monthNumber = num;
	}
	else
	{
		cout << "Error: Invalid month number.";
		exit(EXIT_FAILURE);
	}
}

//Accessors
//Basic accessor for name
string Month::getName()
{
	return name;
}

//Basic accessor for monthNumber
int Month::getMonth()
{
	return monthNumber;
}

//Overloads
//Prefix ++ operator
Month Month::operator++()
{
	//Adds 1 and keeps it clamped between 1 and 12
	monthNumber = (monthNumber % 12) + 1;
	name = intToMonth(monthNumber);
	return *this;
}

//Postfix ++ operator
Month Month::operator++(int)
{
	Month tempMonth = *this;
	++*this;
	return tempMonth;
}

//Prefix -- operator
Month Month::operator--()
{
	//Subtracts 1 and keeps it clamped between 1 and 12
	monthNumber = ((monthNumber + 10) % 12) + 1;
	name = intToMonth(monthNumber);
	return Month();
}

//Postfix -- operator
Month Month::operator--(int)
{
	Month tempMonth = *this;
	--*this;
	return tempMonth;
}

//<< overload to print the object
ostream& operator<<(ostream& strm, Month& obj)
{
	strm << "Name: " << obj.name << " Month: " << obj.monthNumber;
	return strm;
}

//>> overload to set the object's month when called
istream& operator>>(istream& strm, Month& obj)
{
	//Simply ask the user for a month try to make it the new value
	string s;
	cout << "Month: ";
	strm >> s;
	obj.setName(s);
	return strm;
}
