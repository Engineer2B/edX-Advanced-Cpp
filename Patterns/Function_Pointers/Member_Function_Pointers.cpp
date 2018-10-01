#include <iostream>
#include <string>

using namespace std;

// Normal function pointer
void printString(string s) { cout << s << endl << flush; }

// Member function pointer.
class funcPointer {
public:
	void printString(string s) { cout << s << endl << flush; }
};

// Polymorphism use.
class Base {
public:
	virtual void sayHello() { cout << "Hello from Base class. \n" << flush; }
};

class Derived : public Base {
public:
	void sayHello() { cout << "Hello from Derived class. \n" << flush; }
};

int main(int argc, char* argv[]) {
	// Standard function pointer example
	string ss = "Hello World.";

	void (*funcPtr)(string) = &printString;

	(*funcPtr)(ss);

	// Member function pointer example.
	string str = "Hello from member function pointer.!!";
	void (funcPointer::*memFuncPtr)(string) = &funcPointer::printString;

	funcPointer fP;

	(fP.*memFuncPtr)(str);

	// Virtual member function example.
	void (Base::*baseFuncPtr)() = &Base::sayHello;
	void (Derived::*derivedFuncPtr)() = &Derived::sayHello;

	Base bP;
	Derived dP;

	(bP.*baseFuncPtr)(); // call Base::sayHello
	(dP.*derivedFuncPtr)(); // call Derived::sayHello
	(dP.*baseFuncPtr)(); // call Derived::sayHello using base pointer and derived object.

	return 0;
}