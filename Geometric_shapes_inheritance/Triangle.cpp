#include "Triangle.h"


Triangle::Triangle(string nam, string desc) :Shape{ nam,desc }
{
}

int Triangle::get_h() const
{
	return h;
}

int Triangle::get_b() const
{
	return b;
}

void Triangle::set_h(int h)
{
	this->h = h;
}

void Triangle::set_b(int b)
{
	this->b = b;
}



