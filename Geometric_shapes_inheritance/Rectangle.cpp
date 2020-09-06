#include "Rectangle.h"



Rectangle::Rectangle(int a, int b, string nam, string desc) :Shape{nam,desc}, height{ b }, width{ a }
{}

int Rectangle::get_height() const
{
	return this->height;
}

int Rectangle::get_width() const
{
	return this->width;
}

void Rectangle::set_height(int num)
{
	this->height = num;
}

void Rectangle::set_width(int num)
{
	this->width = num;
}


//string Rectangle::toString() const
//{
//	ostringstream ss;
//	/*ss << "Shape Information\n" << "-----------------\n";
//	ss << setw(15) << left << "id:" << getId() << endl;
//	ss << setw(15) << "Shape name:" << getName() << endl;
//	ss << setw(15) << "Description:" << getDesc() << endl;
//	ss << setw(15) << "B. box width:" << boxWidth() << endl;
//	ss << setw(15) << "B. box height:" << boxHeight() << endl;
//	ss << setw(15) << "Scr area:" << screenArea() << endl;
//	ss << setw(15) << "Geo area:" << fixed << setprecision(2) << geoArea() << endl;
//	ss << setw(15) << "Scr perimeter:" << setprecision(0) << screenPerimeter() << endl;
//	ss << setw(15) << "Geo perimeter:" << setprecision(2) << geoPerimeter() << endl;
//	ss << setw(15) << left << "Static type:" << typeid(this).name() << endl;
//	ss << setw(15) << "Dynamic type:" << typeid(*this).name() << endl;
//	ss << setprecision(0) << endl << endl;*/
//
//
//	ss << "Shape Information\n" << "-----------------\n";
//	ss << "id:" << get_id() << endl;
//	ss << "Shape name:" << get_name() << endl;
//	ss << "Description:" << get_description() << endl;
//	ss <<  "B. box width:" << get_width() << endl;
//	ss <<   "B. box height:" << get_height() << endl;
//	ss <<  "Scr area:" << get_screen_area()<< endl;
//	ss <<  "Geo area:" << fixed << get_area() << endl;
//	ss << "Scr perimeter:" << get_screen_perimeter() << endl;
//	ss << "Geo perimeter:" << get_perimeter() << endl;
//	ss <<  "Static type:" << typeid(this).name() << endl;
//	ss <<  "Dynamic type:" << typeid(*this).name() << endl;
//	//ss << setprecision(0) << endl << endl;
//	return ss.str();
//}

double Rectangle::get_area() const
{
	return this->height * this->width;
}

double Rectangle::get_perimeter() const
{
	return 2.0 * (this->height+this->width);
}

int Rectangle::get_screen_area() const
{
	return this->get_area();
}

int Rectangle::get_screen_perimeter() const
{
	return (2 * (this->height + this->width)-4);
}

int Rectangle::get_bounding_box_height() const
{
	return this->get_height();
}

int Rectangle::get_bounding_box_width() const
{
	return this->get_width();
}

Grid Rectangle::draw(char fChar, char bChar) const
{
	Grid rect_grid;
	for (int i = 0; i < this->height; ++i)
	{
		rect_grid.push_back(vector<char>());
		for (int j = 0; j < this->width; ++j)
		{
			rect_grid[i].push_back(fChar);
		}
	}
	return rect_grid;
}
