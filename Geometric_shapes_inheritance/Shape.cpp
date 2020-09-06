#include "Shape.h"


int Shape::count{ 0 };
Shape::Shape(string nam, string desc) :name{ nam }, description{ desc }
{
	count++;
	this->unique_id_num = count;
}

string Shape::get_name() const
{
	return this->name;
}

string Shape::get_description() const
{
	return this->description;
}

int Shape::get_id() const
{
	return this->unique_id_num;
}

void Shape::set_name(string& nam)
{
	this->name = nam;
}

void Shape::set_description(string&des)
{
	this->description = des;
}



string Shape::toString() const
{
	ostringstream ss;
	ss << "Shape Information\n" << "-----------------\n";
	ss <<setw(20) << left << "id:" << get_id() << endl;
	ss << setw(20) << left << "Shape name:" << get_name() << endl;
	ss << setw(20) << left << "Description:" << get_description() << endl;
	ss << setw(20) << left << "B. box width:" << get_width() << endl;
	ss << setw(20) << left << "B. box height:" << get_height() << endl;
	ss << setw(20) << left << "Scr area:" << get_screen_area() << endl;
	ss << setw(20) << left << "Geo area:" << fixed << setprecision(2) << get_area() << endl;
	ss << setw(20) << left << "Scr perimeter:" << get_screen_perimeter() << endl;
	ss << setw(20) << left << "Geo perimeter:" << fixed << setprecision(2)<< get_perimeter() << endl;
	ss << setw(20) << left << "Static type:" << typeid(this).name() << endl;
	ss << setw(20) << left << "Dynamic type:" << typeid(*this).name() << endl;
	//ss << setprecision(0) << endl << endl;
	return ss.str();
}



Shape::~Shape()
{
}

ostream& operator<<(ostream& sout, const Shape& shape)
{
	sout << shape.toString();
	return sout;
}


//SIMPLY LOOPING OVER 2-DIM VECTOR 
ostream& operator<<(std::ostream& sout, const Grid& grid)
{
	
	for (const auto& row : grid)
	{
		for (const auto& s : row) sout << s;
		sout << endl;
	}
	return sout;
}
