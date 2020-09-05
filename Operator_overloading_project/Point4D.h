#pragma once
#include <array>
#include <ostream>
#include <istream>
using std::array;
using std::ostream;
using std::istream;

class Point4D
{
private:

	static double tolerance;
	array<double, 4> coord;


public:
	explicit Point4D(double x = 0, double y = 0, double w = 0, double z = 0);
	Point4D(const Point4D&) = default;
	Point4D& operator=(const Point4D&)=default ;

	double& operator[] (int pos);
	const double& operator[] (int pos) const;
	const Point4D inverse() const ;
	const double operator()() const;
	const double absoluteValue() const;
	//double operator->();


	//UNARY==========================
	Point4D operator-();
	Point4D operator+();
	Point4D operator--(); //pre decrement
	Point4D operator++(); //pre increment
	Point4D operator--(int); //post decrement
	Point4D operator++(int); //post increment

	//COMPOUND OPERATORS===================
	Point4D operator+=(const Point4D& y);
	Point4D operator-=(const Point4D& y);
	Point4D operator*=(const Point4D& y);
	Point4D operator/=(const Point4D& y);

	Point4D operator+=(const double a);
	Point4D operator-=(const double a);
	Point4D operator*=(const double a);
	Point4D operator/=(const double a);

	static void setTolerance(double tol);
	static double getTolerance();


	virtual ~Point4D() = default;
};

//NON MEMBER FUNCTIONS=================================

//Point4D op Point4D
Point4D operator*(const Point4D& x, const Point4D& y);
Point4D operator-(const Point4D& x, const Point4D& y);
Point4D operator+(const Point4D& x, const Point4D& y);
Point4D operator/(const Point4D& x, const Point4D& y);
//Point4D op Point4D  RELATIONAL OPERATORS
const bool operator==(const Point4D& lhs, const Point4D& rhs);
const bool operator!=(const Point4D& lhs, const Point4D& rhs);
const bool operator<=(const Point4D& lhs, const Point4D& rhs);
const bool operator<(const Point4D& lhs, const Point4D& rhs);
const bool operator>(const Point4D& lhs, const Point4D& rhs);
const bool operator>=(const Point4D& lhs, const Point4D& rhs);

//double op Point4D
const Point4D operator+(const double a, const Point4D& x);
const Point4D operator-(const double a, const Point4D& x);
const Point4D operator*(const double a, const Point4D& x);
const Point4D operator/(const double a, const Point4D& x);

//Point4D op double
const Point4D operator+(const Point4D& x, const double a);
const Point4D operator-(const Point4D& x, const double a);
const Point4D operator*(const Point4D& x, const double a);
const Point4D operator/(const Point4D& x, const double a);


//STREAM EXTRACTION
ostream& operator << (ostream& out, const Point4D&);
istream& operator >> (istream& in,  Point4D&);
