#pragma once

#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>

using namespace std;
using std::stringstream;
using Grid = vector<vector<char>>;

class Shape
{
	
private:
	int unique_id_num;
	string name;
	string description;
	static int count;

public:

	Shape(string nam, string desc);

	// GETTERS AND SETTERS
	string get_name() const;
	string get_description() const;
	int get_id() const;

	void set_name(string&);
	void set_description(string&);

	

	//VIRTUAL
	 string toString() const;

	//PURE VIRTUAL FUNCTIONS

	virtual int get_height() const=0;
	virtual int get_width() const=0;
	virtual double get_area() const = 0;
	virtual double get_perimeter() const = 0;
	virtual int get_screen_area() const = 0;
	virtual int get_screen_perimeter() const = 0;
	virtual Grid draw(char fChar = '*', char bChar = ' ') const = 0;
	virtual int get_bounding_box_height() const = 0;
	virtual int get_bounding_box_width() const = 0;
	


	virtual ~Shape();
};




//operator overloading

ostream& operator<< (std::ostream& sout, const Shape& shape);

//to print grid
ostream& operator<< (std::ostream& sout, const Grid& grid);

