//Filename:		Line2D.h
//Name:			Tan Shi Terng Leon
//Declaration:	I did not pass my program to anyone in the class or copy anyone's work 
//				and I am willing to accept whatever penalty given to me and also to all
//				related parties involved
#include "Point3D.h"

class Line2D
{
	friend istream& operator>> (istream&, Line2D&);			//Overloaded extraction operator
	friend ostream& operator<< (ostream&, const Line2D&);	//Overloaded insertion operator

	public:
		Line2D ();	//Empty constructor
		Line2D (const Point2D&, const Point2D&);	//Constructor
		
		void setLength ();		//Computes and sets the length
		
		Point2D getPt1 () const;	//Returns value of pt1
		Point2D getPt2 () const;	//Returns value of pt1
		double getScalarValue () const;	//Returns value of length
		
		void setPt1 (const Point2D&);	//Sets value of pt1
		void setPt2 (const Point2D&);	//Sets value of pt1
		
		Line2D operator- (const Line2D&) const;	//Overloads operator -
		bool operator< (const Line2D&) const;	//Overloads operator <
		bool operator> (const Line2D&) const;	//Overloads operator >
		bool operator== (const Line2D&) const;	//Overloads operator ==
		
	protected:
		double length;	//Distance between pt1 and pt2
		
	private:
		Point2D pt1, pt2;
};

