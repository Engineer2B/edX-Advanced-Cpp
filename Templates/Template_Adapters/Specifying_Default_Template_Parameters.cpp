#include <iostream>

using namespace std;

template<typename A=int, typename B=double , int anint = 5>
void printParams(A ain,B bin) {
	cout << "Arguments are A is type " << typeid(ain).name() << " with value " << ain << " B type is " << typeid(bin).name() << " with value " << bin << " anint is " << anint << endl;
}

template<class C, typename A = int, typename B = double, int anint = 5 >
class myClass {
public:
	myClass(C myc, A ain, B adouble) {
		cout << "myClass constructor parameters myc is type " << typeid(myc).name() << " with value " << myc << " anint is " << ain << " adouble is " << adouble << " anint is " << anint << endl;
	}


};

int main() {

	printParams(99, 33.333);

	cout << "\n";

	int testint = 78;
	myClass<int>(testint,6,6.66);

	cout << "\n";

	return 0;
}
