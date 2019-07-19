#include<iostream>
using namespace std;


class Point
{
	double x;
	double y;
public:
	double get_x() const
	{
		return x;
	}
	double get_y() const
	{
		return y;
	}
	void set_x(double x)
	{
		if (x >= -100 && x <= 100)
		{
			this->x = x;
		}
		else
		{
			throw exception("Bad x");
		}
	}
	void set_y(double y)
	{
		this->y = y;
	}
	//==================================================================================================конструкторы===================================================================================================//
	//==================================================================================================конструкторы===================================================================================================//
	//==================================================================================================конструкторы===================================================================================================//
	//==================================================================================================конструкторы===================================================================================================//




	///////////////////////////////////////////////////////////////////////////////////////////////////DISTANCE FUNCTION///////////////////////////////////////////////////////////////////////////////////////////////////	
	/*double Distance(const Point& other)
	{
	//double x_distance = this->x - other.x;
	//double y_distance = this->y - other.y;
	//return sqrt(x_distance * x_distance + y_distance * y_distance);
	return sqrt(pow(this->x - other.x, 2) + pow(this->y - other.y, 2));
	} */

	///////////////////////////////////////////////////////////////////////////////////////////////////CONSTRUCTOR 1///////////////////////////////////////////////////////////////////////////////////////////////////	
	/*Point()
	{
	x = y = 0;
	cout << "Constructor: " << this << endl;
	}*/


	///////////////////////////////////////////////////////////////////////////////////////////////////CONSTRUCTOR COPY///////////////////////////////////////////////////////////////////////////////////////////////////	
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor: " << this << endl;
	}

	Point(double x = 0, double y = 0)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor: " << this << endl;
	}
	~Point()
	{
		cout << "Destructor: " << this << endl;
	}

	Point& operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssigment: " << this << endl;
		return *this;
	}

	void Print()
	{
		cout << "x = " << x << "\ty = " << y << endl;
	}


	double distance(Point& other)
	{
		return sqrt(pow(this->x - other.x, 2) + pow(this->y - other.y, 2));
	}

};


///////////////////////////////////////////////////////////////////////////////////////////////////DISTANCE FUNCTION///////////////////////////////////////////////////////////////////////////////////////////////////
/* double Distance(Point A, Point B)
{
//double x_distance = A.get_x() - B.get_x();
//double y_distance = A.get_y() - B.get_y();
//return sqrt(x_distance * x_distance + y_distance + y_distance);
return sqrt(pow(A.get_x() - B.get_x(), 2) + pow(A.get_y() - B.get_y(), 2));
} */

void main()
{
	setlocale(LC_ALL, "Rus");
	system("COLOR 0B");
	//int a;
	//Point A;
	//Point B;
	//A.set_x(2);
	//A.set_y(3);
	/* //A.x = 2;
	//A.y = 3;
	//A.set_x(200);
	//A.set_y(3);
	//cout << A.get_x() << "\t" << A.get_y() << endl; // POINT OPERATOR.
	//Point* pA = &A;
	//cout << pA->get_x() << "\t" << pA->get_y() << endl;
	//cout << (*pA).get_x() << "\t" << (*pA).get_y() << endl;
	B.set_x(2);
	B.set_y(5);*/
	//cout << A.Distance(B) << endl;
	//cout << Distance(A, B) << endl;
	Point A; //Defolt Constructor.
	A.Print();
	Point B(2, 3);
	B.Print();
	Point C = 5;
	C.Print();
	//	Point D = B;
	//	D.Print(); 

		//cout << A.Distance(B) << endl;
	//Point A(2, 3);
		//Point B;
		//B = A;
}

