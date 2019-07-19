#include <iostream>
using namespace std;

/*
Home work: Проверчный код должен заработать
*/

class Fraction
{
	int integer;//целое 
	int numerator;// числитель
	int denominator;//знаменатель

public:
	int get_integer() const
	{
		return integer;
	}
	int get_numerator() const
	{
		return numerator;
	}
	int get_denominator() const
	{
		return denominator;
	}



	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		this->denominator = denominator;
	}

	//			Constructors:
	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout << "DefConstructor: \t" << this << endl;
	}
	Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "Constructor: \t" << this << endl;
	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		this->denominator = denominator;
		cout << "constructor: \t" << this << endl;
	}
	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		this->denominator = denominator;
		cout << "constructor: \t" << this << endl;
	}
	~Fraction()
	{
		cout << "destructor: \t" << this << endl;
	}

	//			Methods:
	void to_proper()
	{
		//переводит дробь в правильную
		integer = numerator / denominator;
		numerator %= denominator;
	}
	void to_improper()
	{
		//переводит дробь в неправильную
		numerator += denominator * integer;
		integer = 0;
	}
	void reduce()
	{
		//сокращает дробь
		int more, less, reminder;
		if (numerator > denominator)
		{
			more = numerator;
			less = denominator;
		}
		else
		{
			more = denominator;
			less = numerator;
		}

		do
		{
			reminder = more % less;
			more = less;
			less = reminder;
		} while (reminder);
		int GCD = more;	//Greatest Common Divisor - Наибольший общий делитель
		numerator /= GCD;
		denominator /= GCD;
	}
	void Print()
	{
		cout << integer << "(" << numerator << "/" << denominator << ")" << endl;
	}

	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->denominator = other.denominator;
		this->numerator = other.numerator;
		cout << "CopyAssigment " << this << endl;
		return*this;
	}

	//===========================================================ПЕРЕГРУЗКА (++A, B++) ПЕРЕГРУЗКА======================================================//
	Fraction operator++()
	{
		this->to_proper();
		this->integer++;
		return*this;
	}

	Fraction operator++(int)
	{
		Fraction temp = *this;
		this->to_proper();
		this->integer++;
		return*this;
	}

};
//===========================================================ПЕРЕГРУЗКА (* , / , + , - ,) ПЕРЕГРУЗКА======================================================//
Fraction operator*(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return Fraction(left.get_numerator()*right.get_numerator(), left.get_denominator()*right.get_denominator());
}

Fraction operator/(Fraction left, Fraction right)
{
	left.to_proper();
	right.to_proper();
	return Fraction(left.get_numerator() * right.get_denominator(), left.get_denominator() * right.get_numerator());
}

Fraction operator+(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return Fraction(left.get_numerator()* right.get_denominator() + right.get_numerator()*left.get_denominator(), left.get_denominator()*right.get_denominator());

}

Fraction operator-(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return Fraction(left.get_numerator()*right.get_denominator() - right.get_numerator()* left.get_denominator(), left.get_denominator()* right.get_denominator());
}

//===========================================================ПЕРЕГРУЗКА (+=, -=, *=, /=) ПЕРЕГРУЗКА======================================================//
Fraction operator+=(Fraction left, Fraction right)
{
	left = left + right;
	return left;
}

Fraction operator-=(Fraction left, Fraction right)
{
	left = left - right;
	return left;
}

Fraction operator*=(Fraction left, Fraction right)
{
	left = left * right;
	return left;
}

Fraction operator/=(Fraction left, Fraction right)
{
	left = left / right;
	return left;
}

//===========================================================ПЕРЕГРУЗКА (==, <, >, != , <= , >= ,) ПЕРЕГРУЗКА======================================================//
bool operator==(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return left.get_numerator()*right.get_denominator() == right.get_numerator()*left.get_denominator();
}

bool operator<(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return left.get_numerator()*right.get_denominator() < right.get_numerator()*left.get_denominator();
}

bool operator>(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return left.get_numerator()*right.get_denominator() > right.get_numerator()*left.get_denominator();
}

bool operator !=(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return left.get_numerator()*right.get_denominator() != right.get_numerator()*left.get_denominator();
}

bool operator <=(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return left.get_numerator()*right.get_denominator() <= right.get_numerator()*left.get_denominator();
}

bool operator >=(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return left.get_numerator()*right.get_denominator() >= right.get_numerator()*left.get_denominator();
}

ostream& operator<<(ostream& os, const Fraction& obj)
{
	if (obj.get_integer() != 0)os << obj.get_integer();
	if (obj.get_numerator() != 0)
	{
		if (obj.get_integer() != 0)os << "(" << obj.get_numerator() << "/" << obj.get_denominator() << ")";
		else os << obj.get_numerator() << "/" << obj.get_denominator();
	}
	if (obj.get_numerator() == 0 && obj.get_integer() == 0)os << 0;
	return os;
}

void main()
{
	Fraction A(4, 1, 2);
	cout << A << endl;
	A.to_improper();
	cout << A << endl;
	A.to_proper();
	cout << A << endl;

	Fraction B(5, 3, 10);
	cout << B << endl;
	B.to_improper();
	cout << B << endl;

	Fraction C(35, 155);
	cout << C << endl;
	C.reduce();
	cout << C << endl;

	cout << "=============================OPERATORS (*, /, +, -, ++A, B++)=============================" << endl;
	cout << "|---------------------------------------|" << endl;
	cout << A << " * " << B << " = " << A * B << endl;
	cout << "|---------------------------------------|" << endl;
	cout << A << " / " << B << " = " << A / B << endl;
	cout << "|---------------------------------------|" << endl;
	cout << A << " + " << B << " = " << A + B << endl;
	cout << "|---------------------------------------|" << endl;
	cout << A << " - " << B << " = " << A - B << endl;
	cout << "|---------------------------------------|" << endl;
	cout << ++A << endl;
	cout << "|---------------------------------------|" << endl;
	cout << B++ << endl;
	cout << "=============================OPERATORS (+=, -=, *=, /=)=============================" << endl;
	cout << "|---------------------------------------|" << endl;
	cout << A << " += " << B << " = " << (A += B) << endl;
	cout << "|---------------------------------------|" << endl;
	cout << A << " -= " << B << " = " << (A -= B) << endl;
	cout << "|---------------------------------------|" << endl;
	cout << A << " *= " << B << " = " << (A *= B) << endl;
	cout << "|---------------------------------------|" << endl;
	cout << A << " /= " << B << " = " << (A /= B) << endl;
	cout << "=============================OPERATORS (==, <, >, !=, <=, >=)=============================" << endl;
	cout << "|---------------------------------------|" << endl;
	cout << A << " == " << B << " = " << "bool: " << (A == B) << endl;
	cout << "|---------------------------------------|" << endl;
	cout << A << " < " << B << " = " << "bool: " << (A < B) << endl;
	cout << "|---------------------------------------|" << endl;
	cout << A << " > " << B << " = " << "bool: " << (A > B) << endl;
	cout << "|---------------------------------------|" << endl;
	cout << A << " != " << B << " = " << "bool: " << (A != B) << endl;
	cout << "|---------------------------------------|" << endl;
	cout << A << " <= " << B << " = " << "bool: " << (A <= B) << endl;
	cout << "|---------------------------------------|" << endl;
	cout << A << " >= " << B << " = " << "bool: " << (A >= B) << endl;
}