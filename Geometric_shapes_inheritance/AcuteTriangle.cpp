#include "AcuteTriangle.h"



AcuteTriangle::AcuteTriangle(int base, string nam, string desc) :Triangle{ nam,desc }
{
	base = base % 2 == 0 ? base + 1 : base; // if b is even then make it b+1 else store b
	this->set_b(base);
	this->set_h((base+1)/2);
}

	int AcuteTriangle::get_height() const
	{
		return this->get_h();
	}

	int AcuteTriangle::get_width() const
	{
		return this->get_b();
	}

	double AcuteTriangle::get_area() const
	{
		return (this->get_h() * this->get_b()) / 2.0;
	}

	double AcuteTriangle::get_perimeter() const
	{
		return (get_width() + sqrt(pow(get_width(),2)+4*pow(get_height(),2)));
	}

	int AcuteTriangle::get_screen_area() const
	{
		return pow(this->get_height(),2);
	}

	int AcuteTriangle::get_screen_perimeter() const
	{
		return 4 * (this->get_height() - 1);
	}

	int AcuteTriangle::get_bounding_box_height() const
	{
		return this->get_height();
	}

	int AcuteTriangle::get_bounding_box_width() const
	{
		return this->get_width();
	}

	Grid AcuteTriangle::draw(char fChar, char bChar) const
	{
		Grid at_grid;
		// position and position2 are used to keep track of the edges
		int position{ this->get_width() / 2 };
		int position2{ this->get_width() / 2 };
		for (int r = 0; r < this->get_height(); ++r)
		{
			at_grid.push_back(vector<char>());
			for (int c = 0; c < this->get_width(); ++c)
			{
				if (c >= position && c <= position2)
				{
					at_grid[r].push_back(fChar);
				}
				else
				{
					at_grid[r].push_back(bChar);
				}
			}
			position -= 1;
			position2 += 1;
		}
		return at_grid;
	}

