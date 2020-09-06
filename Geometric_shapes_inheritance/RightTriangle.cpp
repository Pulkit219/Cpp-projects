#include "RightTriangle.h"

RightTriangle::RightTriangle(int base, string nam, string desc):Triangle{nam,desc}
{
	this->set_b(base);
	this->set_h(base);
}

int RightTriangle::get_height() const
{
	return this->get_h();
}

int RightTriangle::get_width() const
{
	return this->get_b();
}

double RightTriangle::get_area() const
{
	return (this->get_h() * this->get_b()) / 2.0;
}

double RightTriangle::get_perimeter() const
{
	return (2 + sqrt(2.0)) * this->get_h();
}

int RightTriangle::get_screen_area() const
{
	return this->get_h() * (this->get_h() + 1) / 2;
}

int RightTriangle::get_screen_perimeter() const
{
	return 3 * (this->get_b() - 1);
}

int RightTriangle::get_bounding_box_height() const
{
	return this->get_height();
}

int RightTriangle::get_bounding_box_width() const
{
	return this->get_width();
}

Grid RightTriangle::draw(char fChar, char bChar) const
{
	Grid rt_grid;
	// position and position2 are used to keep track of the edges
	int position{ 0 };
	for (int r = 0; r < this->get_height(); ++r)
	{
		rt_grid.push_back(vector<char>());
		for (int c = 0; c < this->get_width(); ++c)
		{
			if (c <= position)
			{
				rt_grid[r].push_back(fChar);
			}
			else
			{
				rt_grid[r].push_back(bChar);
			}
		}
		position += 1;
	}
	return rt_grid;
}




