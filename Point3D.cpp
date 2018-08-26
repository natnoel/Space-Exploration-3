//Filename:		Point3D.cpp
//Name:			Tan Shi Terng Leon
//Declaration:	I did not pass my program to anyone in the class or copy anyone's work 
//				and I am willing to accept whatever penalty given to me and also to all
//				related parties involved
#include "Point3D.h"

istream& operator>> (istream& is, Point3D& p)
{
	is.ignore (7, '[');
	is>>p.x;
	is.ignore (7, ' ');
	is>>p.y;
	is.ignore (7, ' ');
	is>>p.z;
	
	return is;
}

ostream& operator<< (ostream& os, const Point3D& p)
{
	os<<fixed<<showpoint<<setprecision (3)
		<<"["<<setw (4)<<p.x<<", "<<setw (4)<<p.y<<", "<<setw (4)<<p.z
		<<"]";
}

Point3D::Point3D ()
{
}

Point3D::Point3D (const int& x, const int& y, const int& z): Point2D (x, y)
{
	this -> z = z;
}
		
void Point3D::setZ (const int& z)
{
	this -> z = z;
}
		
int Point3D::getZ () const
{
	return z;
}
		
void Point3D::setDistFrOrigin ()
{
	Point2D::setDistFrOrigin ();
	
	distFrOrigin = sqrt ((distFrOrigin * distFrOrigin) + (z * z));
}

Point3D Point3D::operator- (const Point3D& pt) const
{
	Point3D newPoint (x - pt.x, y - pt.y, z - pt.z);
	
	newPoint.setDistFrOrigin ();
	
	return newPoint;
}

bool Point3D::operator< (const Point3D& pt) const
{
	return distFrOrigin < pt.distFrOrigin;
}

bool Point3D::operator> (const Point3D& pt) const
{
	return distFrOrigin > pt.distFrOrigin;
}

bool Point3D::operator== (const Point3D& pt) const
{
	return (x == pt.x && y == pt.y && z == pt.z);
}

