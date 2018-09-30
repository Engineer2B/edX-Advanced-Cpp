#include <iostream>

using namespace std;

void printTypeName(int x) {
	cout << "printTypeName parameter type int " << typeid(x).name() << endl;
}

void printTypeName(float x) {
	cout << "printTypeName parameter type float " << typeid(x).name() << endl;
}

void printTypeName(bool x) {
	cout << "printTypeName parameter type bool " << typeid(x).name() << endl;
}

void printTypeName(double x) {
	cout << "printTypeName parameter type double " << typeid(x).name() << endl;
}

template<typename T>
void printTemplateTypeName(T x) {
	cout << "printTemplateTypeName typename parameter " << typeid(x).name() << endl;
}

int main() {
	int myint = 5;
	float myfloat = 7.987654321f;
	bool mybool = false;
	double mydouble = 99.9;

	//Overloaded printTypeName functions.
	printTypeName(myint);
	printTypeName(myfloat);
	printTypeName(mybool);
	printTypeName(mydouble);

	//Temmplate function calls.
	//Specify template function.
	printTemplateTypeName<>(myint);
	printTemplateTypeName<>(myfloat);
	printTemplateTypeName<>(mybool);
	printTemplateTypeName<>(mydouble);

	//Implicit type parametrizing.
	printTemplateTypeName(myint);
	printTemplateTypeName(myfloat);
	printTemplateTypeName(mybool);
	printTemplateTypeName(mydouble);

	//Explicit type parametrizing.
	printTemplateTypeName<int>(myint);
	printTemplateTypeName<float>(myfloat);
	printTemplateTypeName<bool>(mybool);
	printTemplateTypeName<double>(mydouble);

	return 0;
}