#pragma once
#include "Shape.h"
class Rhombus :public Shape
{
private:
	int d;

public:
	Rhombus(int diag, string name = "Diamond", string desc = "Parallelogram with equal sides");

	//SETTERS 

	void set_d(int);
	



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

