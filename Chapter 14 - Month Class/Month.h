#pragma once
#include <iostream>

using namespace std;

#ifndef MONTH_H
#define MONTH_H

class Month
{
	private:
		string name;
		int monthNumber;

		//Helper functions for converting month to int and viceversa
		static int monthToInt(string);
		static string intToMonth(int);

	public:
		//Constructors
		Month();			//Default constructor that sets name to "January." and monthNumber to "1"
		Month(string);		//Accepts name and sets the corresponding monthNumber
		Month(int);			//Accepts monthNumber and sets the corresponding name

		//Mutator
		void setName(string);
		void setMonth(int);

		//Accessors
		string getName();
		int getMonth();

		//Operator overloads
		//Prefix ++
		Month operator++();
		//Postfix ++
		Month operator++(int);
		//Prefix --
		Month operator--();
		//postfix --
		Month operator--(int);
		//<< overload
		friend ostream& operator<<(ostream& strm, Month& obj);
		//>> overload
		friend istream& operator>>(istream& strm, Month& obj);
};



#endif 
