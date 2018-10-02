#include "../../Common/Some_Object.hpp"
#include <vector>

using namespace std;

template<class classType> class LazyObject {
public:
	LazyObject() : objPtr(NULL) {}

	~LazyObject() {
		if(this->objPtr) {
			delete this->objPtr;
		}
	}

	classType& operator*() { return *(this->getInstance()); }

	classType* operator->() { return this->getInstance(); }

private:
	classType* objPtr;
	classType* getInstance(void) {
		if(!this->objPtr) {
			this->objPtr = new classType();
		}
		return this->objPtr;
	}
};

int main(int argc, char* argv[]) {
	cout << "wat";
	vector<LazyObject<someObject>> lazyVec;

	for(int i = 0; i < 10; i++) {
		lazyVec.push_back(LazyObject<someObject>());
	}

	for(int t = 0; t < 10; t++) {
		if(t % 2 == 0) {
			// Access lazyVec element causes someObject to be created.
			lazyVec[t]->printAttr();
		}
	}

	return 0;
}