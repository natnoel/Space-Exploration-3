//Filename:		Line3D.cpp
//Name:			Tan Shi Terng Leon
//Declaration:	I did not pass my program to anyone in the class or copy anyone's work 
//				and I am willing to accept whatever penalty given to me and also to all
//				related parties involved
#include "Line3D.h"

istream& operator>> (istream& is, Line3D& line)
{
	is>>line.pt1;
	is>>line.pt2;
	
	return is;
}

ostream& operator<< (ostream& os, const Line3D& line)
{
	os<<line.pt1<<"   "<<line.pt2;
}

Line3D::Line3D ()
{
}

Line3D::Line3D (const Point3D& pt1, const Point3D& pt2)
{
	this -> pt1 = pt1;
	this -> pt2 = pt2;
}
		
void Line3D::setLength ()
{
	length = sqrt ((pt1.getX () - pt2.getX ()) * (pt1.getX () - pt2.getX ()) +
					(pt1.getY () - pt2.getY ()) * (pt1.getY () - pt2.getY ()) +
					(pt1.getZ () - pt2.getZ ()) * (pt1.getZ () - pt2.getZ ()));
}
		
Point3D Line3D::getPt1 () const
{
	return pt1;
}

Point3D Line3D::getPt2 () const
{
	return pt2;
}
		
void Line3D::setPt1 (Point3D pt1)
{
	this -> pt1 = pt1;
}

void Line3D::setPt2 (Point3D pt2)
{
	this -> pt2 = pt2;
}

Line3D Line3D::operator- (const Line3D& line) const
{
	Line3D newLine (pt1 - line.pt1, pt2 - line.pt2);
	newLine.setLength ();
	
	return newLine;
}

bool Line3D::operator< (const Line3D& line) const
{
	return length < line.length;
}

bool Line3D::operator> (const Line3D& line) const
{
	return length > line.length;
}

bool Line3D::operator== (const Line3D& line) const
{
	return (pt1 == line.pt1 && pt2 == line.pt2);
}

