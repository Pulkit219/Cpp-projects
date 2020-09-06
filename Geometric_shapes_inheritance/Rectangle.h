#pragma once
#include "Shape.h"
class Rectangle :public Shape
{

private:
	int height, width;

public:

	Rectangle(int a, int b, string name="Rectangle", string desc="Four right angles");
	//Rectangle() = delete;

	//SETTERS

	void set_height(int);
	void set_width(int);


	//OVERRIDING SHAPE VIRTUAL METHODS

	int get_height() const override;
	int get_width() const override;

	virtual double get_area() const  override;
	virtual double get_perimeter() const override;
	virtual int get_screen_area() const override;
	virtual int get_screen_perimeter() const override;
	virtual int get_bounding_box_height() const override;
	virtual int get_bounding_box_width() const override;
	virtual Grid draw(char fChar = '*', char bChar = ' ') const override;

	
};

