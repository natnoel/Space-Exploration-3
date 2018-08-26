//Filename:		Line2D.cpp
//Name:			Tan Shi Terng Leon
//Declaration:	I did not pass my program to anyone in the class or copy anyone's work 
//				and I am willing to accept whatever penalty given to me and also to all
//				related parties involved
#include "Line2D.h"

//Overloaded extraction operator
istream& operator>> (istream& is, Line2D& line)
{
	is>>line.pt1;
	is>>line.pt2;
	
	return is;
}

//Overloaded insertion operator
ostream& operator<< (ostream& os, const Line2D& line)
{
	os<<line.pt1<<"   "<<line.pt2;
}

//Empty constructor
Line2D::Line2D ()
{
	//Nothing written here
}

//Constructor
Line2D::Line2D (const Point2D& pt1, const Point2D& pt2)
{
	this -> pt1 = pt1;
	this -> pt2 = pt2;
}

//Computes and sets the length
void Line2D::setLength ()
{
	length = sqrt ((pt1.getX () - pt2.getX ()) * (pt1.getX () - pt2.getX ()) + 
				(pt1.getY () - pt2.getY ()) * (pt1.getY () - pt2.getY ()));
}

//Returns value of pt1
Point2D Line2D::getPt1 () const
{
	return pt1;
}

//Returns value of pt2
Point2D Line2D::getPt2 () const
{
	return pt2;
}

//Returns value of length
double Line2D::getScalarValue () const
{
	return length;
}

//Sets value of pt1
void Line2D::setPt1 (const Point2D& pt1)
{
	this -> pt1 = pt1;
}

//Sets value of pt2
void Line2D::setPt2 (const Point2D& pt2)
{
	this -> pt2 = pt2;
}

//Overloads operator -
Line2D Line2D::operator- (const Line2D& line) const
{
	Line2D newLine (pt1 - line.pt1, pt2 - line.pt2);
	newLine.setLength ();
	
	return newLine;
}

//Overloads operator <
bool Line2D::operator< (const Line2D& line) const
{
	return length < line.length;
}

//Overloads operator >
bool Line2D::operator> (const Line2D& line) const
{
	return length > line.length;
}

//Overloads operator ==
bool Line2D::operator== (const Line2D& line) const
{
	return (pt1 == line.pt1 && pt2 == line.pt2);
}

