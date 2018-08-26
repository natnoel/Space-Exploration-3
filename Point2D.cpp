//Filename:		Point2D.cpp
//Name:			Tan Shi Terng Leon
//Declaration:	I did not pass my program to anyone in the class or copy anyone's work 
//				and I am willing to accept whatever penalty given to me and also to all
//				related parties involved
#include "Point2D.h"

istream& operator>> (istream& is, Point2D& p)
{
	is.ignore (7, '[');
	is>>p.x;
	is.ignore (7, ' ');
	is>>p.y;
	
	return is;
}

ostream& operator<< (ostream& os, const Point2D& p)
{
	os<<fixed<<showpoint<<setprecision (3)
		<<"["<<setw (4)<<p.x<<", "<<setw (4)<<p.y<<"]";
}

Point2D::Point2D ()
{
}

Point2D::Point2D (int x, int y)
{
	this -> x = x;
	this -> y = y;
}
		
void Point2D::setX (const int& x)
{
	this -> x = x;
}

void Point2D::setY (const int& y)
{
	this -> y = y;
}
		
int Point2D::getX () const
{
	return x;
}

int Point2D::getY () const
{
	return y;
}

double Point2D::getScalarValue () const
{
	return distFrOrigin;
}
		
void Point2D::setDistFrOrigin ()
{
	distFrOrigin = sqrt ((x * x) + (y * y));
}

Point2D Point2D::operator- (const Point2D& pt) const
{
	Point2D newPoint (x - pt.x, y - pt.y);
	
	newPoint.setDistFrOrigin ();
	
	return newPoint;
}

bool Point2D::operator< (const Point2D& pt) const
{
	return distFrOrigin < pt.distFrOrigin;
}

bool Point2D::operator> (const Point2D& pt) const
{
	return distFrOrigin > pt.distFrOrigin;
}

bool Point2D::operator== (const Point2D& pt) const
{
	return (x == pt.x && y == pt.y);
}

