//Filename:		Line3D.h
//Name:			Tan Shi Terng Leon
//Declaration:	I did not pass my program to anyone in the class or copy anyone's work 
//				and I am willing to accept whatever penalty given to me and also to all
//				related parties involved
#include "Line2D.h"

class Line3D: public Line2D
{
	friend istream& operator>> (istream&, Line3D&);
	friend ostream& operator<< (ostream&, const Line3D&);

	public:
		Line3D ();
		Line3D (const Point3D&, const Point3D&);
		
		void setLength ();
		
		Point3D getPt1 () const;
		Point3D getPt2 () const;
		
		void setPt1 (Point3D);
		void setPt2 (Point3D);
		
		Line3D operator- (const Line3D&) const;
		bool operator< (const Line3D&) const;
		bool operator> (const Line3D&) const;
		bool operator== (const Line3D&) const;
		
	private:
		Point3D pt1, pt2;
};

