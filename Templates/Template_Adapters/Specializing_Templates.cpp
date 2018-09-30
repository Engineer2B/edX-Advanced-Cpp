#include <iostream>

using namespace std;

template<int N>
void printCountUp() {
	printCountUp<N-1>();
	cout << N << "\n";
}

template<>
void printCountUp<0>() {
	 cout << 0 << "\n";
}

template<typename T>
void printFunction(T arg) {
	cout << "printFunction arg is type " << typeid(arg).name() << " with value " << arg << endl;
}

template<>
void printFunction(int intarg) {
	cout << "printFunction specialization with int arg only called with type " << typeid(intarg).name() << " with value " << intarg << endl;
}

template<class C>
class myClass {
	public:
	myClass() {
		cout << "myClass constructor called" << endl;
	}
};

template<>
class myClass<int> {
	public:
	myClass() {
		cout << "myClass int specialization called. " << endl;
	}
};

template<typename T,int size>
void printParamTypes(T myt) {
	cout << "printParamTypes types are " << typeid(myt).name() << " and size " << typeid(size).name() << " with value " << size << endl;
}


template<int size>
void printParamTypes(char c) {
	cout << "printParamTypes partial specialization types are " << typeid(c).name() << " with value " << c << " and size " << typeid(size).name() << " with value " << size << endl;
}

int main() {
	printFunction(99.9);

	cout << "\n";

	printFunction(9);

	cout << "\n";

	myClass<double>();

	cout << "\n";

	myClass<int>();

	cout << "\n";

	printCountUp<5>();

	cout << "\n";

	printParamTypes<int, 5>(99);

	cout << "\n";

	printParamTypes<5>('A');

	cout << "\n";

	return 0;
}