#include "../../Common/Some_Object.hpp"
#include <ctime>

using namespace std;


template<class classType> class SmartPointer {
private:
	classType* objPtr; // Pointer to object.
public:
	SmartPointer(classType* CT) : objPtr(CT) {}

	~SmartPointer() { delete this->objPtr; }

	classType& operator*() { return *(this->objPtr); }

	classType* operator->() { return this->objPtr; }
};

int main(int argc, char* argv[]) {
	srand(static_cast<unsigned int>(time(NULL)));
	SmartPointer<someObject> spob(new someObject());

	spob->printAttr();

	spob->setString("Set string via smart pointer");

	spob->printAttr();

	return 0;
}