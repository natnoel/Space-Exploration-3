//Filename:		MyTemplates.h
//Name:			Tan Shi Terng Leon
//Declaration:	I did not pass my program to anyone in the class or copy anyone's work 
//				and I am willing to accept whatever penalty given to me and also to all
//				related parties involved

template <class T>
T difference (const T &a, const T &b)
{
	return a - b;
}

template <typename T>
double scalar_difference (const T &a, const T &b)
{
	return a.getScalarValue () - b.getScalarValue ();
}

template <typename T>
bool lessThan (const T &a, const T &b)
{
	return a < b;
}

template <typename T>
bool greaterThan (const T &a, const T &b)
{
	return a > b;
}

template <typename T>
bool equals (const T &a, const T &b)
{
	return a == b;
}

template <class T>
bool cmpX (const T &a, const T &b)
{
	return (a.getX () < b.getX ());
}

template <class T>
bool cmpY (const T &a, const T &b)
{
	return (a.getY () < b.getY ());
}

template <class T>
bool cmpZ (const T &a, const T &b)
{
	return (a.getZ () < b.getZ ());
}

template <typename T>
bool cmpXY (const T &a, const T &b)
{
	bool value;
	
	if (cmpX (a, b))
		value = true;
	else if (a.getX () == b.getX () && cmpY (a, b))
		value = true;
	else
		value = false;
		
	return value;
}

template <class T>
bool cmpPt1 (const T &a, const T &b)
{
	return cmpXY (a.getPt1 (), b.getPt1 ());
}

template <class T>
bool cmpPt2 (const T &a, const T &b)
{
	return cmpXY (a.getPt2 (), b.getPt2 ());
}

