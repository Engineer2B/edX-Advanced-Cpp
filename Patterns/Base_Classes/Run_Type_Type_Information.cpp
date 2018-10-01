#include <iostream>

using namespace std;

class BaseClass {};

class DerivedClass : public BaseClass {};

int main(int argc, char* argv[]) {
	BaseClass bc;
	DerivedClass dc;
	BaseClass* ptr_bc;

	// Dynamic cast
	ptr_bc = dynamic_cast<BaseClass*>(&dc);
	if(ptr_bc) {
		cout << "dynamic_cast completed successfully. \n";
	}

	// Using typeid and type_info struct field name.
	cout << typeid(bc).name() << " " << typeid(dc).name() << "\n";

	return 0;
}