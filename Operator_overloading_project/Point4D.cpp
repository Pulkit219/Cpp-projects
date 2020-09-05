#include "Point4D.h"
#include <cmath> 
#include <iostream>
using std::abs;
using std::endl;
using std::cout;


/*
.at() array library function is used to catch bounds exception
whereever possible but it was not possible to include
this in non-member functions

*/


double Point4D::tolerance = 1.0E-6;

Point4D::Point4D(double x, double y, double w, double z)
{
    this->coord.at(0) = x;
    this->coord.at(1) = y;
    this->coord.at(2) = w;
    this->coord.at(3) = z;
}






//OVERLOADED SUBSCRIPT [] OPERATOR
double& Point4D::operator[](int pos)
{  
    return this->coord.at(pos - 1);
}

//OVERLOADED SUBSCRIPT [] OPERATOR CONST
const double& Point4D::operator[](int pos) const
{
    return this->coord.at(pos - 1);
}



//double Point4D::operator->()
//{
//    return 0.0;
//}




//DOING INVERSE
const Point4D Point4D::inverse() const
{
    Point4D temp;
    double beta = (this->coord.at(0) * this->coord.at(2) - (this->coord.at(1) * this->coord.at(3)));
  
    if (abs(beta) < tolerance)
    {
        throw std::overflow_error("Encountered division by zero while inverting a Point4D");
    }
    else 
    {
        temp.coord.at(0) = this->coord.at(2) * (1 / beta);
        temp.coord.at(1) = (-this->coord.at(1)) * (1 / beta);
        temp.coord.at(2) = (this->coord.at(0) * (1 / beta));
        temp.coord.at(3) = (-this->coord.at(3) * (1 / beta));

        return temp;

    }

}



 const double Point4D::operator()() const
{
    return absoluteValue();
}
 const double Point4D::absoluteValue() const
{
    double temp=abs(this->coord.at(0))+abs(this->coord.at(1))+abs(this->coord.at(2))+abs(this->coord.at(3));
    return temp;
}




 //UNARY===================================
 Point4D Point4D::operator-()
 {
     Point4D temp;
     temp[1] = -this->coord.at(0);
     temp[2] = -this->coord.at(1);
     temp[3] = -this->coord.at(2);
     temp[4] = -this->coord.at(3);

     return temp;
 }

 Point4D Point4D::operator+()
 {
     return *this;
 }

 Point4D Point4D::operator--()
 {
     Point4D temp;
     this->coord.at(0)--;
     this->coord.at(1)--;
     this->coord.at(2)--;
     this->coord.at(3)--;
     return *this;
 }

 Point4D Point4D::operator--(int)
 {
     Point4D temp = *this;
     --this->coord.at(0);
     --this->coord.at(1);
     --this->coord.at(2);
     --this->coord.at(3);
     return temp;
 }

 Point4D Point4D::operator++()
 {
   
     this->coord.at(0)++;
     this->coord.at(1)++;
     this->coord.at(2)++;
     this->coord.at(3)++;
     return *this;

 }

 Point4D Point4D::operator++(int i)
 {
     Point4D temp = *this;
     ++this->coord.at(0);
     ++this->coord.at(1);
     ++this->coord.at(2);
     ++this->coord.at(3);
     return temp;
 }


 //COMPOUND OPERATORS==============================
 Point4D Point4D::operator+=(const Point4D& y)
 {
     *this= *this+y;
     return *this;
 }

 Point4D Point4D::operator-=(const Point4D& y)
 {
     *this = *this - y;
     return *this;
 }

 Point4D Point4D::operator*=(const Point4D& y)
 {
     *this = *this * y;
     return *this;
 }

 Point4D Point4D::operator/=(const Point4D& y)
 {
     *this = *this / y;
     return *this;
 }

 Point4D Point4D::operator+=(const double a)
 {
     *this = *this + a;
     return *this;
 }

 Point4D Point4D::operator-=(const double a)
 {
     *this = *this - a;
     return *this;
 }

 Point4D Point4D::operator*=(const double a)
 {
     *this = *this * a;
     return *this;
 }

 Point4D Point4D::operator/=(const double a)
 {
     *this = *this / a;
     return *this;
 }




 //GETTER SETTER FOR TOLERANCE=============================
 void Point4D::setTolerance(double tol)
{
    tolerance = abs(tol);
}


double Point4D::getTolerance()
{
    return tolerance;
}






//Point4D op Point4D==========================================
Point4D operator*(const Point4D& x, const Point4D& y)
{
    Point4D temp;
    temp[1] = (x[1] * y[1]) + (x[2] * y[4]);
    temp[2] = (x[1] * y[2]) + (x[2] * y[3]);
    temp[3] = (x[4] * y[2]) + (x[3] * y[3]);
    temp[4] = (x[4] * y[1]) + (x[3] * y[4]);

    return temp;
}


Point4D operator-(const Point4D& x, const Point4D& y)
{
    Point4D temp;
    temp[1] = x[1] - y[1];
    temp[2] = x[2] - y[2];
    temp[3] = x[3] - y[3];
    temp[4] = x[4] - y[4];
    return  temp;
}

Point4D operator+(const Point4D& x, const Point4D& y)
{
    Point4D temp;
    temp[1] = x[1] + y[1];
    temp[2] = x[2] + y[2];
    temp[3] = x[3] + y[3];
    temp[4] = x[4] + y[4];
    return  temp;
}

Point4D operator/(const Point4D& x, const Point4D& y)
{
    return x*y.inverse();
}




//double op Point4D========================================
const Point4D operator+(const double a, const Point4D& x)
{
    Point4D temp;
    temp[1] = a + x[1];
    temp[2] = a + x[2];
    temp[3] = a + x[3];
    temp[4] = a + x[4];
    return temp;
}

const Point4D operator-(const double a, const Point4D& x)
{
    Point4D temp;
    temp[1] = a - x[1];
    temp[2] = a - x[2];
    temp[3] = a - x[3];
    temp[4] = a - x[4];
    return temp;
}

const Point4D operator*(const double a, const Point4D& x)
{
    Point4D temp;
    temp[1] = a * x[1];
    temp[2] = a * x[2];
    temp[3] = a * x[3];
    temp[4] = a * x[4];
    return temp;
}

const Point4D operator/(const double a, const Point4D& x)
{
    Point4D inverse_x = x.inverse();
    Point4D temp = a * inverse_x;
    return temp;
}






//Point4D op double===========================
const Point4D operator+(const Point4D& x, const double a)
{
    return a + x;
}

const Point4D operator-(const Point4D& x, const double a)
{

    Point4D temp;
    temp[1] = x[1]-a;
    temp[2] = x[2]-a;
    temp[3] = x[3]-a;
    temp[4] = x[4]-a;

    return temp;
}

const Point4D operator*(const Point4D& x, const double a)
{
    return a*x; //delegated above, since X * a= a * X
}

const Point4D operator/(const Point4D& x, const double a)
{
    double inverse_a = 1/a;
    return x * inverse_a;
}






//Relational operators==============================================


const bool operator==(const Point4D& lhs, const Point4D& rhs)
{   
    return (abs((lhs()-rhs())) <= Point4D::getTolerance());
}


const bool operator!=(const Point4D& lhs, const Point4D& rhs)
{
    return (abs(lhs() - rhs()) > Point4D::getTolerance());
}

const bool operator<=(const Point4D& lhs, const Point4D& rhs)
{
    return (lhs < rhs || lhs == rhs);
}

const bool operator<(const Point4D& lhs, const Point4D& rhs)
{
    return (lhs() < rhs() && lhs!=rhs);
}

const bool operator>(const Point4D& lhs, const Point4D& rhs)
{
    return (lhs() > rhs() && lhs!= rhs);
}

const bool operator>=(const Point4D& lhs, const Point4D& rhs)
{
    return (lhs > rhs || lhs == rhs);
}



// STREAM EXTRACTION OPERATORS============================
ostream& operator<<(ostream& out, const Point4D& rhs)
{   
    return out << "[" << rhs[1] << "," << rhs[2] << "," << rhs[3] << "," << rhs[4] << "]" << endl;    
}

istream& operator>>(istream& in,  Point4D& rhs)
{
    return in >> rhs[1]>> rhs[2]>> rhs[3]>> rhs[4];
}
