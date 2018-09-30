/*
A copy constructor is used to make a copy of an existing object instance. There are 4 possible function signatures for a copy constructor.

someClass( const someClass& other );
someClass( someClass& other );
someClass( volatile const someClass& other );
someClass( volatile someClass& other );
*/
#include <string>
#include <iostream>
#include "../../Common/memory_leak_detect.h"

using namespace std;

class MyDeepClass
{

public:
	//Constructor
	MyDeepClass(int x, char cc, std::string ss, int *intp);

	//Deep copy constructor
	MyDeepClass(const MyDeepClass &other);

	//Assignment operator
	MyDeepClass &operator=(const MyDeepClass &rhs);

	//Print function.
	void MyDeepClassPrint();
	int *intptr;

private:
	int x;
	char c;
	std::string s;
};

void MyDeepClass::MyDeepClassPrint()
{
	cout << x << " " << c << " " << s << " " << *intptr;
}

MyDeepClass::MyDeepClass(int xx, char cc, std::string ss, int *intp) : x(xx), c(cc), s(ss), intptr(intp)
{
	cout << "MyDeepClass constructor called " << endl;
}

MyDeepClass::MyDeepClass(const MyDeepClass &other) : x(other.x), c(other.c), s(other.s)
{
	//copy intptr memory.
	cout << "MyDeepClass copy constructor called " << endl;
	this->intptr = new int(*other.intptr);
}

MyDeepClass &MyDeepClass::operator=(const MyDeepClass &rhs)
{
	// cout << "MyDeepClass operator= called." << endl;
	//Check for self assignment.
	if (this != &rhs)
	{
		this->x = rhs.x;
		this->c = rhs.c;
		this->s = rhs.s;
		if (this->intptr != NULL)
		{
			delete this->intptr;
		}
		this->intptr = new int(*rhs.intptr);
	}
	return *this;
}

class MyShallowClass
{

public:
	MyShallowClass(int xx, char cc, std::string ss) : x(xx), c(cc), s(ss)
	{
		cout << "MyShallowClass constructor called." << endl;
	}

	void MyShallowClassPrint()
	{
		cout << x << " " << c << " " << s;
	}

private:
	int x;
	char c;
	std::string s;
};

int main()
{
	MemLeakCheck(anything);
	int *myint = new int(67);
	int myintx = 55;
	std::string mystring("Hello Deep World");

	int myShallowIntx = 1111;
	std::string myShallowString("Hello Shallow World");

	MyDeepClass mdc(myintx, 'S', mystring, myint); //Declared Constructor
	MyDeepClass mdc2(myintx, 'A', myShallowString, myint);

	MyDeepClass mdcCopy(mdc); //User defined copy constructor

	MyShallowClass msc(myShallowIntx, 'Z', myShallowString); //Declared constructor

	MyShallowClass mscCopy(msc); //Compiler generated copy constructor

	cout << "MyDeepClass mdc member values are ";
	mdc.MyDeepClassPrint();
	cout << endl;

	cout << "MyDeepClass mdcCopy member values are ";
	mdcCopy.MyDeepClassPrint();
	cout << endl;

	cout << "MyShallowClass msc member values are ";
	msc.MyShallowClassPrint();
	cout << endl;

	cout << "MyShallowClass mscCopy member values are ";
	mscCopy.MyShallowClassPrint();
	cout << endl;

	//Create LHS object.
	int *myassignint = new int(1111);
	int myassignintx = 9999;
	std::string myassignstring("Assignment operator");
	MyDeepClass mdcAssign(myassignintx, 'V', myassignstring, myassignint);

	cout << "MyDeepClass mdcAssign member values before assignment are ";
	mdcAssign.MyDeepClassPrint();
	cout << endl;
	mdcAssign.intptr = nullptr;
	//Call assignment operator.
	MemLeakCheckReport(anything);
	for (int i = 0; i < 1000; i++)
	{
		mdcAssign = mdc;
		mdcAssign = mdc2;
	}
	MemLeakCheckReport(anything);
	cout << "MyDeepClass mdcAssign member values after assignment are ";
	mdcAssign.MyDeepClassPrint();
	cout << endl;

	return 0;
}