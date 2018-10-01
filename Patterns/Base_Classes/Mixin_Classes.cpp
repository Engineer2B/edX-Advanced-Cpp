#include <iostream>

using namespace std;

class A {
public:
	void printName() { cout << "A\n"; }
};

template<class classType> class B : public classType {
public:
	void printName() {
		cout << "class B calling A::printName() \n";
		classType::printName();
	}
};

template<class classType> class C : public classType {
public:
	void printName() {
		cout << "class C calling B::printName() \n";
		classType::printName();
	}
};

int main(int argc, char* argv[]) {
	// Create mixin class.
	C<B<A>> myMixin;

	myMixin.printName();

	return 0;
}