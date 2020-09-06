#include "Rhombus.h"

Rhombus::Rhombus(int diag, string name, string desc):Shape{name,desc},d{diag}
{
	d = diag % 2 == 0 ? diag + 1 : diag; // if d is even then make it d+1 else store d
}

int Rhombus::get_height() const
{
	return this->d;
}

int Rhombus::get_width() const
{
	return this->d;
}

void Rhombus::set_d(int dia)
{
	dia % 2 == 0 ? d = dia + 1 : d = dia; // if d is even then make it d+1 else store d
}

double Rhombus::get_area() const
{
	return pow(d, 2.0) / 2;
}

double Rhombus::get_perimeter() const
{
	return 2 * sqrt(2.0) * d;
}

int Rhombus::get_screen_area() const
{
	double n = d / 2;
	return (2 * n * (n + 1) + 1);
}

int Rhombus::get_screen_perimeter() const
{
	return 2 * (this->d-1);
}

int Rhombus::get_bounding_box_height() const
{
	return this->d;
}

int Rhombus::get_bounding_box_width() const
{
	return this->d;
}

Grid Rhombus::draw(char fChar, char bChar) const
{
	Grid rhombus_grid;
	// position and position2 are used to keep track of the edges of the rhombus
	int position{ this->get_height() / 2 };
	int position2{ this->get_height() / 2 };
	for (int r = 0; r < this->get_height(); ++r)
	{
		rhombus_grid.push_back(vector<char>());
		// For the top half of the rhombus
		if (r < this->get_height() / 2)
		{
			for (int c = 0; c < this->get_width(); ++c)
			{
				if (c >= position && c <= position2)
				{
					rhombus_grid[r].push_back(fChar);
				}
				else
				{
					rhombus_grid[r].push_back(bChar);
				}
			}
			position -= 1;
			position2 += 1;
		}
		else
		{
			// For the bottom half of the rhombus
			for (int c = 0; c < this->get_width(); ++c)
			{
				if (c >= position && c <= position2)
				{
					rhombus_grid[r].push_back(fChar);
				}
				else
				{
					rhombus_grid[r].push_back(bChar);
				}
			}
			position += 1;
			position2 -= 1;
		}
	}
	return rhombus_grid;
}
