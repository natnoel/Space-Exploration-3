//Filename:		Point3D.h
//Name:			Tan Shi Terng Leon
//Declaration:	I did not pass my program to anyone in the class or copy anyone's work 
//				and I am willing to accept whatever penalty given to me and also to all
//				related parties involved
#include "Point2D.h"

class Point3D: public Point2D
{
	friend istream& operator>> (istream&, Point3D&);
	friend ostream& operator<< (ostream&, const Point3D&);

	public:
		Point3D ();
		Point3D (const int&, const int&, const int&);
		
		void setZ (const int&);
		
		int getZ () const;
		
		virtual void setDistFrOrigin ();
		
		Point3D operator- (const Point3D&) const;
		bool operator< (const Point3D&) const;
		bool operator> (const Point3D&) const;
		bool operator== (const Point3D&) const;
		
	private:
		int z;
};

