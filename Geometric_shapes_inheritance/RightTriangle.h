#pragma once
#include "Triangle.h"
class RightTriangle :public Triangle
{
private:
	//int b;
public:
	RightTriangle(int , string nam = "Ladder", string desc = "One right and two acute angles");



	//OVERRIDING PURE VIRTUAL


	virtual int get_height() const override;
	virtual int get_width() const override;

	virtual double get_area() const  override;
	virtual double get_perimeter() const override;
	virtual int get_screen_area() const override;
	virtual int get_screen_perimeter() const override;
	virtual int get_bounding_box_height() const override;
	virtual int get_bounding_box_width() const override;
	virtual Grid draw(char fChar = '*', char bChar = ' ') const override;
};

