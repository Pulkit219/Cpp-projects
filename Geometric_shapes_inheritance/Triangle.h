#pragma once
#include "Shape.h"
class Triangle :public Shape
{
private:
	int h, b;


public:
	Triangle(string nam, string desc);

	//SETTERS AND GETTERS
	int get_h() const;
	int get_b() const;
	void set_h(int);
	void set_b(int);

	//VIRTUAL FUNCTIONS
	

	//PURE VIRTUAL FUNCTIONS
	virtual int get_height() const = 0;
	virtual int get_width() const = 0;
	virtual double get_area() const=0 ;

	//DESTRUCTOR
	//virtual ~Triangle();
};

