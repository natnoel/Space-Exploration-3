//Filename:		Point2D.h
//Name:			Tan Shi Terng Leon
//Declaration:	I did not pass my program to anyone in the class or copy anyone's work 
//				and I am willing to accept whatever penalty given to me and also to all
//				related parties involved
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

class Point2D
{
	friend istream& operator>> (istream&, Point2D&);
	friend ostream& operator<< (ostream&, const Point2D&);
	
	public:
		Point2D ();
		Point2D (int, int);
		
		void setX (const int&);
		void setY (const int&);
		
		int getX () const;
		int getY () const;
		double getScalarValue () const;
		
		void setDistFrOrigin ();
		
		Point2D operator- (const Point2D&) const;
		bool operator< (const Point2D&) const;
		bool operator> (const Point2D&) const;
		bool operator== (const Point2D&) const;
	
	protected:
		int x, y;
		double distFrOrigin;
};

