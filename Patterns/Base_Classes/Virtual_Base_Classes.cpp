#include <iostream>

using namespace std;

class A {
public:
	void printName() { cout << "A\n"; }
};

class B : public A {};

class C : public A {};

class CB : public B, public C {};

class D : public virtual A {};

class F : public virtual A {};

class DF : public D, public F {};

int main(int argc, char* argv[]) {
	// CB cb;
	// cb.printName();  //Compiler error ambigous printName

	DF df;
	df.printName();

	return 0;
}