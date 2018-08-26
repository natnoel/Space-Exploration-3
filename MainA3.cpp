//Filename:		MainA3.cpp
//Name:			Tan Shi Terng Leon
//Declaration:	I did not pass my program to anyone in the class or copy anyone's work 
//				and I am willing to accept whatever penalty given to me and also to all
//				related parties involved
#include "MyTemplates.h"
#include "Line3D.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <sstream>
using namespace std;

ostream& dottedLine (ostream&);

class A3Driver
{
	public:
		A3Driver ();
		int main ();
		
	private:
		int choice;		//For main menu as it has more than 9 (single digit) options
		char option;	//For submenus
		
		//Indicators for type of view
		string filterBy, sortBy, sortOrder;
		
		fstream file, infile, outfile;
		char fileName [50];
		int x, y, z;
		Point2D p2D, p2D1;
		Point3D p3D, p3D1;
		Line2D line2D;
		Line3D line3D;
		double max, min, avg;
		
		//Containers
		vector<Point2D> p2DList;	//Stores Point2D objects
		vector<Point3D> p3DList;	//Stores Point3D objects
		vector<Line2D> line2DList;	//Stores Line2D objects
		vector<Line3D> line3DList;	//Stores Line3D objects
		
		int recordsRead;
		
		//Generates messy.txt
		void generateMessyText ();
		
		//Reads data from file
		void fileToVector ();
		
		//Display functions
		string p2DListAsc ();
		string p2DListDsc ();
		string p3DListAsc ();
		string p3DListDsc ();
		string l2DListAsc ();
		string l2DListDsc ();
		string l3DListAsc ();
		string l3DListDsc ();
		
		//Sorting functions
		void sortP2D ();
		void sortP3D ();
		void sortL2D ();
		void sortL3D ();
		
		//Deleting functions
		bool deleteP2D ();
		bool deleteP3D ();
		bool deleteL2D ();
		bool deleteL3D ();
		
		//Stores output into a file
		void vectorToFile ();
		
		//Get statistics
		void getP2DStats ();
		void getP3DStats ();
		void getL2DStats ();
		void getL3DStats ();
		
		void line () const;
};

A3Driver::A3Driver ()
{
	filterBy = "Point2D";
	sortBy = "x-ordinate";
	sortOrder = "ASC";
}

int A3Driver::main ()
{	 
	srand (time (NULL));
	
	cout<<"Welcome to Assn3 program!"<<endl<<endl;
	
	do
	{
		cout<<"Main Menu"<<endl
			<<"========="<<endl<<endl
			<<"1)	Read in data"<<endl
			<<"2)	Specify filtering criteria (current: "<<filterBy<<")"<<endl
			<<"3)	Specify sorting criteria (current: "<<sortBy<<")"<<endl
			<<"4)	Specify sorting order (current: "<<sortOrder<<")"<<endl
			<<"5)	View Data"<<endl
			<<"6)	Store Date"<<endl
			<<"7)	Create a random data text file (eg. messy.txt)"<<endl
			<<"8)	Delete an object"<<endl
			<<"9)	Add an object"<<endl
			<<"10)	Show statistical information"<<endl
			<<"11)	Exit program"<<endl<<endl
			<<"Please enter your choice: ";
			
		cin>>choice;
		line ();
		cout<<endl;
		
		switch (choice)
		{
			case 1:	 	/***********************Read in data***********************/
						try
						{
							cout<<"Please enter filename: ";
							cin.clear ();
							cin.ignore (100, '\n');
							cin.getline (fileName, 50);
							cout<<endl;
							fileToVector ();
						}
						catch (string errorMsg)
						{
							cout<<"Error: "<<errorMsg<<endl;
						}
						break;
						
			case 2:	  	/******************Specifying filtering criteria******************/
						cout<<"Specifying filtering criteria (current: "<<filterBy<<endl
							<<"=================================================="<<endl
							<<"	a)	Point2D records"<<endl
							<<"	b)	Point3D records"<<endl
							<<"	c)	Line2D records"<<endl
							<<"	d)	Line3D records"<<endl<<endl
							<<"Please enter your criteria (a - d): ";
						cin>>option;
						switch (option)
						{
							case 'a':	filterBy = "Point2D";
										if (sortBy != "x-ordinate")
											sortBy = "x-ordinate";
										break;
										
							case 'b':	filterBy = "Point3D";
										if (sortBy != "x-ordinate")
											sortBy = "x-ordinate";
										break;
										
							case 'c':	filterBy = "Line2D";
										if (sortBy != "Pt. 1")
											sortBy = "Pt. 1";
										break;
										
							case 'd':	filterBy = "Line3D";
										if (sortBy != "Pt. 1")
											sortBy = "Pt. 1";
										break;
										
							default:	cout<<"Invalid option!"<<endl;
						}
						
						if (option == 'a' || option == 'b' || option == 'c' || option == 'd')
						{
							if (sortOrder != "ASC")
								sortOrder = "ASC";

							cout<<"Filter criteria successfully set to '"
								<<filterBy<<"'!"<<endl;
						}
						
						break;
						
			case 3:	  	/******************Specifying sorting criteria******************/
						cout<<"Specify sorting criteria (current: "<<sortBy<<")"<<endl
							<<"========================================="<<endl<<endl;
						if (filterBy == "Point2D" || filterBy == "Point3D")
						{
							cout<<"\ta)\tx-ordinate values"<<endl
								<<"\tb)\ty-ordinate values"<<endl;
							if (filterBy == "Point2D")
								cout<<"\tc)\tDistance from origin"<<endl<<endl;
							else
							{
								cout<<"\tc)\tz-ordinate values"<<endl
									<<"\td)\tDistance from origin"<<endl<<endl;
							}
						}
						else
						{
							cout<<"\ta)\tPt. 1's (x, y) values"<<endl
								<<"\tb)\tPt. 2's (x, y) values"<<endl
								<<"\tc)\tLength value"<<endl<<endl;
						}
						
						cout<<"Please enter your criteria (a - ";
						cout<<(filterBy == "Point3D" ? "d" : "c")<<"): ";
						
						
						cin>>option;
						
						if (filterBy == "Point2D" || filterBy == "Point3D")
						{
							switch (option)
							{
								case 'a':	sortBy = "x-ordinate";
											break;
											
								case 'b':	sortBy = "y-ordinate";
											break;
											
								case 'c':	if (filterBy == "Point2D")
												sortBy = "Dist. from origin";
											else
												sortBy = "x-ordinate";
											break;
											
								case 'd':	if (filterBy == "Point3D")
												sortBy = "Dist. from origin";
											else
												cout<<"Invalid option!"<<endl;
											break;
											
								default:	cout<<"Invalid option!"<<endl;
							}
						}
						else
						{
							switch (option)
							{
								case 'a':	sortBy = "Pt. 1";
											break;
											
								case 'b':	sortBy = "Pt. 2";
											break;
											
								case 'c':	sortBy = "Length";
											break;
											
								default:	cout<<"Invalid option!"<<endl;
							}
						}
						
						if (option == 'a' || option == 'b' || option == 'c')
							cout<<"Sorting criteria successfully set to '"<<sortBy<<"'!"
								<<endl;
						break;
						
			case 4:	 	/******************Specifying sorting order******************/
						cout<<"Specifying sorting order (current: "<<sortOrder<<")"<<endl
							<<"======================================="<<endl<<endl
							<<"\ta)\tASC (Ascending order)"<<endl
							<<"\tb)\tDSC (Descending order)"<<endl<<endl
							<<"Please enter your criteria (a - b): ";
						cin>>option;
						switch (option)
						{
							case 'a':	sortOrder = "ASC";
										break;
							case 'b':	sortOrder = "DSC";
										break;
							default:	cout<<"Invalid option!"<<endl;
						}
						
						if (option == 'a' || option == 'b')
							cout<<"Sorting criteria successfully set to '"<<sortOrder<<")!"
								<<endl;
						break;
						
			case 5:	  	/***************************View data***************************/
						cout<<"View data"<<endl
							<<"========="<<endl<<endl
							<<"Filtering criteria: "<<filterBy<<endl
							<<"Sorting criteria: "<<sortBy<<endl
							<<"Sorting order: "<<sortOrder<<endl<<endl;
						
						/*******Sorting*******/
						if (filterBy == "Point2D")
						{
							sortP2D ();
							
							if (sortOrder == "ASC")
								cout<<p2DListAsc ();
							else
								cout<<p2DListDsc ();
						}
						else if (filterBy == "Point3D")
						{
							sortP3D ();
							
							if (sortOrder == "ASC")
								cout<<p3DListAsc ();
							else
								cout<<p3DListDsc ();
						}
						else if (filterBy == "Line2D")
						{
							sortL2D ();
							
							if (sortOrder == "ASC")
								cout<<l2DListAsc ();
							else
								cout<<l2DListDsc ();
						}
						else
						{
							sortL3D ();
							
							if (sortOrder == "ASC")
								cout<<l3DListAsc ();
							else
								cout<<l3DListDsc ();
						}
						
						break;
						
			case 6:	  	/*************************Store Date*************************/
						cout<<"Please enter the name of the file u wish to store the data: ";
						cin.clear ();
						cin.ignore (100, '\n');
						cin.getline (fileName, 50);
						cout<<endl;
						
						try
						{
							vectorToFile ();
						}
						catch (string errorMsg)
						{
							cout<<"Error: "<<errorMsg<<endl;
						}
						
						break;
						
			case 7:	  	/*********Create a random data text file (eg. messy.txt)*********/
						cout<<"Enter the name of the data file: ";
						cin.clear ();
						cin.ignore (100, '\n');
						cin.getline (fileName, 50);
						
						try
						{
							generateMessyText ();
							cout<<fileName<<" successfully generated!"<<endl;
						}
						catch (string errorMsg)
						{
							cout<<"Error: "<<errorMsg<<endl;
						}
						
						break;
						
			case 8:	  	/********************Delete an object********************/
						cout<<"Which object do you want to delete?"<<endl<<endl
							<<"a)\tPoint2D object"<<endl
							<<"b)\tPoint3D object"<<endl
							<<"c)\tLine2D object"<<endl
							<<"d)\tLine3D object"<<endl<<endl
							<<"Please enter your option: ";
							
						cin>>option;
						cout<<endl;
						
						switch (option)
						{
							case 'a':	try
										{
											if (p2DList.empty ())
											{
												string errorMsg = "Point2D list is empty!";
												throw errorMsg;
											}
											
											do
											{
												cout<<"Enter x-ordinate: ";
												cin>>x;
												
												if (x < -999 || x > 999)
													cout<<"x must be more than -999 "
														<<"and less than 999!"<<endl;
											}while (x < -999 || x > 999);
											
											do
											{
												cout<<"Enter y-ordinate: ";
												cin>>y;
												
												if (y < -999 || y > 999)
													cout<<"y must be more than -999 "
														<<"and less than 999!"<<endl;
											}while (y < -999 || y > 999);
											
											cout<<endl;
											
											p2D.setX (x);
											p2D.setY (y);
											
											if (deleteP2D ())
												cout<<"Point2D "<<p2D<<" successfully deleted!"
													<<endl;
											else
												cout<<"Point2D "<<p2D<<" does not exist!"<<endl;
										}
										catch (string errorMsg)
										{
											cout<<"Error: "<<errorMsg<<endl;
										}
											
										break;
							
							case 'b':	try
										{
											if (p3DList.empty ())
											{
												string errorMsg = "Point3D list is empty!";
												throw errorMsg;
											}
											
											do
											{
												cout<<"Enter x-ordinate: ";
												cin>>x;
												
												if (x < -999 || x > 999)
													cout<<"x must be more than -999 "
														<<"and less than 999!"<<endl;
											}while (x < -999 || x > 999);
											
											do
											{
												cout<<"Enter y-ordinate: ";
												cin>>y;
												
												if (y < -999 || y > 999)
													cout<<"y must be more than -999 "
														<<"and less than 999!"<<endl;
											}while (y < -999 || y > 999);
											
											do
											{
												cout<<"Enter z-ordinate: ";
												cin>>z;
												
												if (z < -999 || z > 999)
													cout<<"z must be more than -999 "
														<<"and less than 999!"<<endl;
											}while (z < -999 || z > 999);
											
											cout<<endl;
											
											p3D.setX (x);
											p3D.setY (y);
											p3D.setZ (z);
											
											if (deleteP3D ())
												cout<<"Point3D "<<p3D<<" successfully deleted!"
													<<endl;
											else
												cout<<"Point3D "<<p3D<<" does not exist!"<<endl;
										}
										catch (string errorMsg)
										{
											cout<<"Error: "<<errorMsg<<endl;
										}
										
										break;
										
							case 'c':	try
										{
											if (line2DList.empty ())
											{
												string errorMsg = "Line2D list is empty!";
												throw errorMsg;
											}
											
											do
											{
												cout<<"Enter x-ordinate of pt1: ";
												cin>>x;;
												
												if (x < -999 || x > 999)
													cout<<"x must be more than -999 "
														<<"and less than 999!"<<endl;
											}while (x < -999 || x > 999);
											
											do
											{
												cout<<"Enter y-ordinate of pt1: ";
												cin>>y;
												
												if (y < -999 || y > 999)
													cout<<"y must be more than -999 "
														<<"and less than 999!"<<endl;
											}while (y < -999 || y > 999);
											
											cout<<endl;
											
											p2D.setX (x);
											p2D.setY (y);
											
											do
											{
												cout<<"Enter x-ordinate of pt2: ";
												cin>>x;;
												
												if (x < -999 || x > 999)
													cout<<"x must be more than -999 "
														<<"and less than 999!"<<endl;
											}while (x < -999 || x > 999);
											
											do
											{
												cout<<"Enter y-ordinate of pt2: ";
												cin>>y;
												
												if (y < -999 || y > 999)
													cout<<"y must be more than -999 "
														<<"and less than 999!"<<endl;
											}while (y < -999 || y > 999);
											cout<<endl;
											
											p2D1.setX (x);
											p2D1.setY (y);
											
											line2D.setPt1 (p2D);
											line2D.setPt2 (p2D1);
											
											if (deleteL2D ())
												cout<<"Line2D "<<line2D<<" successfully deleted!"
													<<endl;
											else
												cout<<"Line2D "<<line2D<<" does not exist!"<<endl;
										}
										catch (string errorMsg)
										{
											cout<<"Error: "<<errorMsg<<endl;
										}
										break;
										
							case 'd':	
										try
										{
											if (line3DList.empty ())
											{
												string errorMsg = "Line3D list is empty!";
												throw errorMsg;
											}
											do
											{
												cout<<"Enter x-ordinate of pt1: ";
												cin>>x;;
												
												if (x < -999 || x > 999)
													cout<<"x must be more than -999 "
														<<"and less than 999!"<<endl;
											}while (x < -999 || x > 999);
											
											do
											{
												cout<<"Enter y-ordinate of pt1: ";
												cin>>y;
												
												if (y < -999 || y > 999)
													cout<<"y must be more than -999 "
														<<"and less than 999!"<<endl;
											}while (y < -999 || y > 999);
											
											do
											{
												cout<<"Enter z-ordinate of pt1: ";
												cin>>z;
												
												if (z < -999 || z > 999)
													cout<<"z must be more than -999 "
														<<"and less than 999!"<<endl;
											}while (z < -999 || z > 999);
											
											cout<<endl;
											
											p3D.setX (x);
											p3D.setY (y);
											p3D.setZ (z);
											
											do
											{
												cout<<"Enter x-ordinate of pt2: ";
												cin>>x;;
												
												if (x < -999 || x > 999)
													cout<<"x must be more than -999 "
														<<"and less than 999!"<<endl;
											}while (x < -999 || x > 999);
											
											do
											{
												cout<<"Enter y-ordinate of pt2: ";
												cin>>y;
												
												if (y < -999 || y > 999)
													cout<<"y must be more than -999 "
														<<"and less than 999!"<<endl;
											}while (y < -999 || y > 999);
											
											do
											{
												cout<<"Enter z-ordinate of pt2: ";
												cin>>z;
												
												if (z < -999 || z > 999)
													cout<<"z must be more than -999 "
														<<"and less than 999!"<<endl;
											}while (z < -999 || z > 999);
											cout<<endl;
											
											p3D1.setX (x);
											p3D1.setY (y);
											p3D1.setZ (z);
											
											line3D.setPt1 (p3D);
											line3D.setPt2 (p3D1);
											
											if (deleteL3D ())
												cout<<"Line3D "<<line3D<<" successfully deleted!"
													<<endl;
											else
												cout<<"Line3D "<<line3D<<" does not exist!"<<endl;
										}
										catch (string errorMsg)
										{
											cout<<"Error: "<<errorMsg<<endl;
										}
										break;
										
							default:	cout<<"Invalid option!"<<endl;
						}
						break;
						
			case 9:		/********************Add an object********************/
						cout<<"Which object do you want to add?"<<endl<<endl
							<<"a)\tPoint2D object"<<endl
							<<"b)\tPoint3D object"<<endl
							<<"c)\tLine2D object"<<endl
							<<"d)\tLine3D object"<<endl<<endl
							<<"Please enter your option: ";
							
						cin>>option;
						cout<<endl;
						
						switch (option)
						{
							case 'a':	do
										{
											cout<<"Enter x-ordinate: ";
											cin>>x;
											
											if (x < -999 || x > 999)
												cout<<"x must be more than -999 "
													<<"and less than 999!"<<endl;
										}while (x < -999 || x > 999);
										
										do
										{
											cout<<"Enter y-ordinate: ";
											cin>>y;
											
											if (y < -999 || y > 999)
												cout<<"y must be more than -999 "
													<<"and less than 999!"<<endl;
										}while (y < -999 || y > 999);
										
										cout<<endl;
										
										p2D.setX (x);
										p2D.setY (y);
										p2D.setDistFrOrigin ();
										
										if (count (p2DList.begin (), p2DList.end (), p2D) 
											== 0)
										{
											p2DList.push_back (p2D);
											cout<<"Point2D "<<p2D<<" successfully inserted!"
												<<endl;
										}
										else
											cout<<"Point2D "<<p2D<<" already exist!"<<endl;
											
										break;
							
							case 'b':	do
										{
											cout<<"Enter x-ordinate: ";
											cin>>x;
											
											if (x < -999 || x > 999)
												cout<<"x must be more than -999 "
													<<"and less than 999!"<<endl;
										}while (x < -999 || x > 999);
										
										do
										{
											cout<<"Enter y-ordinate: ";
											cin>>y;
												
											if (y < -999 || y > 999)
												cout<<"y must be more than -999 "
													<<"and less than 999!"<<endl;
										}while (y < -999 || y > 999);
										
										do
										{
											cout<<"Enter z-ordinate: ";
											cin>>z;
											
											if (z < -999 || z > 999)
												cout<<"z must be more than -999 "
													<<"and less than 999!"<<endl;
										}while (z < -999 || z > 999);
										cout<<endl;
										
										p3D.setX (x);
										p3D.setY (y);
										p3D.setZ (z);
										p3D.setDistFrOrigin ();
										
										if (count (p3DList.begin (), p3DList.end (), p3D) 
											== 0)
										{
											p3DList.push_back (p3D);
											cout<<"Point3D "<<p3D<<" successfully added!"
												<<endl;
										}
										else
											cout<<"Point3D "<<p3D<<" already exist!"<<endl;
										
										break;
										
							case 'c':	do
										{
											cout<<"Enter x-ordinate of pt1: ";
											cin>>x;;
											
											if (x < -999 || x > 999)
												cout<<"x must be more than -999 "
													<<"and less than 999!"<<endl;
										}while (x < -999 || x > 999);
										
										do
										{
											cout<<"Enter y-ordinate of pt1: ";
											cin>>y;
											
											if (y < -999 || y > 999)
												cout<<"y must be more than -999 "
													<<"and less than 999!"<<endl;
										}while (y < -999 || y > 999);
										cout<<endl;
										
										p2D.setX (x);
										p2D.setY (y);
										
										do
										{
											cout<<"Enter x-ordinate of pt2: ";
											cin>>x;;
											
											if (x < -999 || x > 999)
												cout<<"x must be more than -999 "
													<<"and less than 999!"<<endl;
										}while (x < -999 || x > 999);
										
										do
										{
											cout<<"Enter y-ordinate of pt2: ";
											cin>>y;
											
											if (y < -999 || y > 999)
												cout<<"y must be more than -999 "
													<<"and less than 999!"<<endl;
										}while (y < -999 || y > 999);
										cout<<endl;
										
										p2D1.setX (x);
										p2D1.setY (y);
										
										line2D.setPt1 (p2D);
										line2D.setPt2 (p2D1);
										line2D.setLength ();
										
										if (count (line2DList.begin (), line2DList.end (), 
											line2D) == 0)
										{
											line2DList.push_back (line2D);
											cout<<"Line2D "<<line2D<<" successfully added!"
												<<endl;
										}
										else
											cout<<"Line2D "<<line2D<<" already exist!"<<endl;
											
										break;
										
							case 'd':	do
											{
												cout<<"Enter x-ordinate of pt1: ";
												cin>>x;;
												
												if (x < -999 || x > 999)
													cout<<"x must be more than -999 "
														<<"and less than 999!"<<endl;
											}while (x < -999 || x > 999);
											
											do
											{
												cout<<"Enter y-ordinate of pt1: ";
												cin>>y;
												
												if (y < -999 || y > 999)
													cout<<"y must be more than -999 "
														<<"and less than 999!"<<endl;
											}while (y < -999 || y > 999);
											
											do
											{
												cout<<"Enter z-ordinate of pt1: ";
												cin>>z;
												
												if (z < -999 || z > 999)
													cout<<"z must be more than -999 "
														<<"and less than 999!"<<endl;
											}while (z < -999 || z > 999);
										cout<<endl;
										
										p3D.setX (x);
										p3D.setY (y);
										p3D.setZ (z);
										
										do
										{
											cout<<"Enter x-ordinate of pt2: ";
											cin>>x;;
											
											if (x < -999 || x > 999)
												cout<<"x must be more than -999 "
													<<"and less than 999!"<<endl;
										}while (x < -999 || x > 999);
										
										do
										{
											cout<<"Enter y-ordinate of pt2: ";
											cin>>y;
											
											if (y < -999 || y > 999)
												cout<<"y must be more than -999 "
													<<"and less than 999!"<<endl;
										}while (y < -999 || y > 999);
										
										do
										{
											cout<<"Enter z-ordinate of pt2: ";
											cin>>z;
											
											if (z < -999 || z > 999)
												cout<<"z must be more than -999 "
													<<"and less than 999!"<<endl;
										}while (z < -999 || z > 999);
										
										cout<<endl;
										
										p3D1.setX (x);
										p3D1.setY (y);
										p3D1.setZ (z);
										
										line3D.setPt1 (p3D);
										line3D.setPt2 (p3D1);
										line3D.setLength ();
										
										if (count (line3DList.begin (), line3DList.end (), 
											line3D) == 0)
										{
											line3DList.push_back (line3D);
											cout<<"Line3D "<<line3D<<" successfully added!"
												<<endl;
										}
										else
											cout<<"Line3D "<<line3D<<" already exist!"<<endl;
											
										break;
										
							default:	cout<<"Invalid option!"<<endl;
						}
						break;
						
			case 10:	/**********************Statistics**********************/
						if (p2DList.size () > 0)
						{
							getP2DStats ();
							cout<<"Point2D statistics"<<endl
								<<"=================="<<endl
								<<"Total number of Point2D objects: "<<p2DList.size ()<<endl
								<<"Maximum dist. from origin: "<<max<<endl
								<<"Minimum dist. from origin: "<<min<<endl
								<<"Average dist. from origin: "<<avg<<endl<<endl;
						}
						else
							cout<<"Point2D list is empty"<<endl;
						
						if (p3DList.size () > 0)
						{
							getP3DStats ();
							cout<<"Point3D statistics"<<endl
								<<"=================="<<endl
								<<"Total number of Point3D objects: "<<p3DList.size ()<<endl
								<<"Maximum dist. from origin: "<<max<<endl
								<<"Minimum dist. from origin: "<<min<<endl
								<<"Average dist. from origin: "<<avg<<endl<<endl;
						}
						else
							cout<<"Point3D list is empty"<<endl;
						
						if (line2DList.size () > 0)
						{
							getL2DStats ();
							cout<<"Line2D statistics"<<endl
								<<"=================="<<endl
								<<"Total number of Point3D objects: "<<line2DList.size ()<<endl
								<<"Maximum length: "<<max<<endl
								<<"Minimum length: "<<min<<endl
								<<"Average length: "<<avg<<endl<<endl;
						}
						else
							cout<<"Line2D list is empty"<<endl;
						
						if (line3DList.size () > 0)
						{
							getL3DStats ();
							cout<<"Line3D statistics"<<endl
								<<"=================="<<endl
								<<"Total number of Point3D objects: "<<line3DList.size ()<<endl
								<<"Maximum length: "<<max<<endl
								<<"Minimum length: "<<min<<endl
								<<"Average length: "<<avg<<endl<<endl;
						}
						else
							cout<<"Line3D list is empty"<<endl;
							
						break;
						
			case 11:	cout<<"Thank you and have a nice day!"<<endl;
						break;
			
			default:	cout<<"Invalid option!"<<endl;
		}
		
		line ();

	}while (choice != 11);
	return 0;
}

/*******************************Reads data from file*******************************/
void A3Driver::fileToVector ()
{
	infile.open (fileName, ios::in);

	if (!infile)
	{
		string errorMsg = "File not found!";
		throw errorMsg;
	}
	
	string type;
	recordsRead = 0;
	
	while (getline (infile, type, ','))
	{
		if (type == "Point2D")
		{
			infile>>p2D;
			p2D.setDistFrOrigin ();
			
			if (find (p2DList.begin (), p2DList.end (), p2D) == p2DList.end ())
			{
				p2DList.push_back (p2D);
				cout<<"Stored Point2D object "<<p2D<<endl;
				recordsRead++;
			}
			else
				cout<<"Point2D object "<<p2D<<" already exist! Data not stored."<<endl;
				
			infile.ignore (7, '\n');
		}
		else if (type == "Point3D")
		{
			infile>>p3D;
			p3D.setDistFrOrigin ();
			
			if (find (p3DList.begin (), p3DList.end (), p3D) == p3DList.end ())
			{
				p3DList.push_back (p3D);
				cout<<"Stored Point3D object "<<p3D<<endl;
				recordsRead++;
			}
			else
				cout<<"Point3D object "<<p3D<<" already exist! Data not stored."<<endl;
			
			infile.ignore (7, '\n');
		}
		else if (type == "Line2D")
		{
			infile>>line2D;
			line2D.setLength ();
			
			if (find (line2DList.begin (), line2DList.end (), line2D) == line2DList.end ())
			{
				line2DList.push_back (line2D);
				cout<<"Stored Line2D object "<<line2D<<endl;
				recordsRead++;
			}
			else
				cout<<"Line2D object "<<line2D<<" already exist! Data not stored."<<endl;
				
			infile.ignore (7, '\n');
		}
		else if (type == "Line3D")
		{
			infile>>line3D;
			line3D.setLength ();
			
			if (find (line3DList.begin (), line3DList.end (), line3D) == line3DList.end ())
			{
				line3DList.push_back (line3D);
				cout<<"Stored Line3D object"<<line3D<<endl;
				recordsRead++;
			}
			else
				cout<<"Line3D object "<<line3D<<" already exist! Data not stored."<<endl;
				
			infile.ignore (7, '\n');
		}
	}
	
	cout<<endl<<recordsRead<<" records read in successfully!"<<endl;
	
	infile.close ();
}

/****************************Generates a file(messy.txt) to read****************************/
void A3Driver::generateMessyText ()
{
	int type;
	
	file.open (fileName, ios::out);
	
	if (!file)
	{
		string errorMsg = "Unable to create file!";
		throw errorMsg;
	}
	
	for (int i = 0; i < rand () % 251; i++)
	{
		type = rand () % 4;
		
		switch (type)
		{
			case 0:	file<<"Point2D, ["<<(rand () % 1999) - 999<<", "<<(rand () % 1999) - 999
						<<"]";
					break;
					
			case 1:	file<<"Point3D, ["<<(rand () % 1999) - 999<<", "<<(rand () % 1999) - 999
						<<", "<<(rand () % 1999) - 999<<"]";
					break;
					
			case 2:	file<<"Line2D, ["<<(rand () % 1999) - 999<<", "<<(rand () % 1999) - 999
						<<"], ["<<(rand () % 1999) - 999<<", "<<(rand () % 1999) - 999
						<<"]";
					break;
			
			default:file<<"Line3D, ["<<(rand () % 1999) - 999<<", "<<(rand () % 1999) - 999
						<<", "<<(rand () % 1999) - 999<<"], ["<<(rand () % 1999) - 999<<", "
						<<(rand () % 1999) - 999<<", "<<(rand () % 1999) - 999<<"]";
					break;
		}
		
		file<<endl;
	}
	
	
	file.close ();
}

/*******************************Displays the lists*******************************/
string A3Driver::p2DListAsc ()
{
	stringstream ss;
	ss<<setw (5)<<"X"<<setw (6)<<"Y"<<"    Dist. Fr Origin"<<endl;
	ss<<dottedLine;
	for (vector<Point2D>::iterator it = p2DList.begin (); it < p2DList.end (); it++)
	{
		ss<<*it<<setw (18)<<it -> getScalarValue ()<<endl;
	}
	return ss.str ();
}

string A3Driver::p2DListDsc ()
{
	stringstream ss;
	
	ss<<setw (5)<<"X"<<setw (6)<<"Y"<<"    Dist. Fr Origin"<<endl<<dottedLine;
	
	for (vector<Point2D>::reverse_iterator it = p2DList.rbegin (); it < p2DList.rend (); it++)
	{
		ss<<*it<<setw (18)<<it -> getScalarValue ()<<endl;
	}
	
	return ss.str ();
}

string A3Driver::p3DListAsc ()
{
	stringstream ss;

	ss<<setw (5)<<"X"<<setw (6)<<"Y"<<setw (6)<<"Z"<<"    Dist. Fr Origin"<<endl<<dottedLine;
	
	for (vector<Point3D>::iterator it = p3DList.begin (); it < p3DList.end (); it++)
	{
		ss<<*it<<setw (18)<<it -> getScalarValue ()<<endl;
	}
	
	return ss.str ();
}

string A3Driver::p3DListDsc ()
{
	stringstream ss;
	
	ss<<setw (5)<<"X"<<setw (6)<<"Y"<<setw (6)<<"Z"<<"    Dist. Fr Origin"<<endl<<dottedLine;
	
	for (vector<Point3D>::reverse_iterator it = p3DList.rbegin (); it < p3DList.rend (); it++)
	{
		ss<<*it<<setw (18)<<it -> getScalarValue ()<<endl;
	}
	
	return ss.str ();
}

string A3Driver::l2DListAsc ()
{
	stringstream ss;
	
	ss<<setw (5)<<"P1-X"<<setw (6)<<"P1-Y"<<"    "
		<<setw (5)<<"P2-X"<<setw (6)<<"P2-Y"<<"    Length"<<endl<<dottedLine;
		
	for (vector<Line2D>::iterator it = line2DList.begin (); it < line2DList.end (); it++)
	{
		ss<<*it<<setw (10)<<it -> getScalarValue ()<<endl;
	}
	
	return ss.str ();
}

string A3Driver::l2DListDsc ()
{
	stringstream ss;
	
	cout<<setw (5)<<"P1-X"<<setw (6)<<"P1-Y"<<"    "
		<<setw (5)<<"P2-X"<<setw (6)<<"P2-Y"<<"    Length"<<endl<<dottedLine;
	for (vector<Line2D>::reverse_iterator it = line2DList.rbegin (); it < line2DList.rend ();
		it++)
	{
		ss<<*it<<setw (10)<<it -> getScalarValue ()<<endl;
	}
	
	return ss.str ();
}

string A3Driver::l3DListAsc ()
{
	stringstream ss;
	
	ss<<setw (5)<<"P1-X"<<setw (6)<<"P1-Y"<<setw (6)<<"P1-Z"<<"    "
		<<setw (5)<<"P2-X"<<setw (6)<<"P2-Y"<<setw (6)<<"P2-Z"<<"    Length"<<endl<<dottedLine;
		
	for (vector<Line3D>::iterator it = line3DList.begin (); it < line3DList.end (); it++)
	{
		ss<<*it<<setw (11)<<it -> getScalarValue ()<<endl;
	}
	
	return ss.str ();
}

string A3Driver::l3DListDsc ()
{
	stringstream ss;
	
	ss<<setw (5)<<"P1-X"<<setw (6)<<"P1-Y"<<setw (6)<<"P1-Z"<<"    "
		<<setw (5)<<"P2-X"<<setw (6)<<"P2-Y"<<setw (6)<<"P2-Z"<<"    Length"<<endl<<dottedLine;
		
	for (vector<Line3D>::reverse_iterator it = line3DList.rbegin (); it < line3DList.rend ();
		it++)
	{
		ss<<*it<<setw (11)<<it -> getScalarValue ()<<endl;
	}
	
	return ss.str ();
}

/*******************************Sorts the lists*******************************/
void A3Driver::sortP2D ()
{
	if (sortBy == "x-ordinate")
		sort (p2DList.begin (), p2DList.end (), cmpX<Point2D>);
	else if (sortBy == "y-ordinate")
		sort (p2DList.begin (), p2DList.end (), cmpY<Point2D>);
	else
		sort (p2DList.begin (), p2DList.end ());
}

void A3Driver::sortP3D ()
{
	if (sortBy == "x-ordinate")
		sort (p3DList.begin (), p3DList.end (), cmpX<Point2D>);
	else if (sortBy == "y-ordinate")
		sort (p3DList.begin (), p3DList.end (), cmpY<Point2D>);
	else if (sortBy == "z-ordinate")
		sort (p3DList.begin (), p3DList.end (), cmpZ<Point3D>);	   
	else
		sort (p3DList.begin (), p3DList.end ());
}

void A3Driver::sortL2D ()
{
	if (sortBy == "Pt. 1")
		sort (line2DList.begin (), line2DList.end (), cmpPt1<Line2D>);
	else if (sortBy == "Pt. 2")
		sort (line2DList.begin (), line2DList.end (), cmpPt2<Line2D>);
	else
		sort (line2DList.begin (), line2DList.end ());
}

void A3Driver::sortL3D ()
{
	if (sortBy == "Pt. 1")
		sort (line3DList.begin (), line3DList.end (), cmpPt1<Line3D>);
	else if (sortBy == "Pt. 2")
		sort (line3DList.begin (), line3DList.end (), cmpPt2<Line3D>);
	else
		sort (line3DList.begin (), line3DList.end ());
}

/*******************************Outputs result to a file*******************************/
void A3Driver::vectorToFile ()
{
	outfile.open (fileName, ios::out);
	
	if (!outfile)
	{
		string errorMsg = "Cannot create file !";
		throw errorMsg;
	}
	
	if (filterBy == "Point2D")
	{
		sortP2D ();
							
		if (sortOrder == "ASC")
			outfile<<p2DListAsc ();
		else
			outfile<<p2DListDsc ();
			
		cout<<p2DList.size ()<<" records output successfully!"<<endl;
	}
	else if (filterBy == "Point3D")
	{
		sortP3D ();
							
		if (sortOrder == "ASC")
			outfile<<p3DListAsc ();
		else
			outfile<<p3DListDsc ();
			
		cout<<p3DList.size ()<<" records output successfully!"<<endl;
	}
	else if (filterBy == "Line2D")
	{
		sortL2D ();
							
		if (sortOrder == "ASC")
			outfile<<l2DListAsc ();
		else
			outfile<<l2DListDsc ();
			
		cout<<line2DList.size ()<<" records output successfully!"<<endl;
	}
	else
	{
		sortL3D ();
							
		if (sortOrder == "ASC")
			outfile<<l3DListAsc ();
		else
			outfile<<l3DListDsc ();
		
		cout<<line3DList.size ()<<" records output successfully!"<<endl;
	}
	
	outfile.close ();
}

/*******************************Deletion of an object*******************************/
bool A3Driver::deleteP2D ()
{
	bool deleted = false;

	for (vector<Point2D>::iterator it = p2DList.begin (); it < p2DList.end (); it++)
	{
		if (*it == p2D)
		{
			p2DList.erase (it);
			deleted = true;
		}
	}
	
	return deleted;
}

bool A3Driver::deleteP3D ()
{
	bool deleted = false;

	for (vector<Point3D>::iterator it = p3DList.begin (); it < p3DList.end (); it++)
	{
		if (*it == p3D)
		{
			p3DList.erase (it);
			deleted = true;
		}
	}
	
	return deleted;
}

bool A3Driver::deleteL2D ()
{
	bool deleted = false;

	for (vector<Line2D>::iterator it = line2DList.begin (); it < line2DList.end (); it++)
	{
		if (*it == line2D)
		{
			line2DList.erase (it);
			deleted = true;
		}
	}
	
	return deleted;
}

bool A3Driver::deleteL3D ()
{
	bool deleted = false;

	for (vector<Line3D>::iterator it = line3DList.begin (); it < line3DList.end (); it++)
	{
		if (*it == line3D)
		{
			line3DList.erase (it);
			deleted = true;
		}
	}
	
	return deleted;
}

/***********************************Statistics***********************************/

void A3Driver::getP2DStats ()
{
	Point2D maxPt;
	Point2D minPt;
	double totalDist = 0;
	
	maxPt = p2DList.front ();
	minPt = p2DList.front ();
	
	for (vector<Point2D>::iterator it = p2DList.begin () + 1; it < p2DList.end (); it++)
	{
		if (greaterThan (*it, maxPt))
			maxPt = *it;
		if (lessThan (*it, minPt))
			minPt = *it;
		
		totalDist += it -> getScalarValue ();
	}
	
	max = maxPt.getScalarValue ();
	min = minPt.getScalarValue ();
	avg = totalDist / p2DList.size ();
}

void A3Driver::getP3DStats ()
{
	Point3D maxPt;
	Point3D minPt;
	double totalDist = 0;
	
	maxPt = p3DList.front ();
	minPt = p3DList.front ();
	
	for (vector<Point3D>::iterator it = p3DList.begin () + 1; it < p3DList.end (); it++)
	{
		if (greaterThan (*it, maxPt))
			maxPt = *it;
		if (lessThan (*it, minPt))
			minPt = *it;
		
		totalDist += it -> getScalarValue ();
	}
	
	max = maxPt.getScalarValue ();
	min = minPt.getScalarValue ();
	avg = totalDist / p3DList.size ();
}

void A3Driver::getL2DStats ()
{
	Line2D maxLn;
	Line2D minLn;
	double totalDist = 0;
	
	maxLn = line2DList.front ();
	minLn = line2DList.front ();
	
	for (vector<Line2D>::iterator it = line2DList.begin () + 1; it < line2DList.end (); it++)
	{
		if (greaterThan (*it, maxLn))
			maxLn = *it;
		if (lessThan (*it, minLn))
			minLn = *it;
		
		totalDist += it -> getScalarValue ();
	}
	
	max = maxLn.getScalarValue ();
	min = minLn.getScalarValue ();
	avg = totalDist / line2DList.size ();
}

void A3Driver::getL3DStats ()
{
	Line3D maxLn;
	Line3D minLn;
	double totalDist = 0;
	
	maxLn = line3DList.front ();
	minLn = line3DList.front ();
	
	for (vector<Line3D>::iterator it = line3DList.begin () + 1; it < line3DList.end (); it++)
	{
		if (greaterThan (*it, maxLn))
			maxLn = *it;
		if (lessThan (*it, minLn))
			minLn = *it;
		
		totalDist += it -> getScalarValue ();
	}
	
	max = maxLn.getScalarValue ();
	min = minLn.getScalarValue ();
	avg = totalDist / line3DList.size ();
}

void A3Driver::line () const
{
	cout<<"---------------------------------------------------"<<endl;
}

int main ()
{
	A3Driver A3D;
	A3D.main ();
	return 0;
}

ostream& dottedLine (ostream& os)
{
	os<<"- - - - - - - - - - - - - - - - - - - - - - - - - - -"<<endl;
	return os;
}

