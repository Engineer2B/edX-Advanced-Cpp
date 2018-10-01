#include "../../Common/Referenced_Object.hpp"

#include <string>

using namespace std;

class SSOString : public refCounter {
	// This class provides local storage for short strings, which is a faster type of storage than
	// heap allocation.
public:
	SSOString() : strBeg(NULL) {}

	SSOString(const char* strptr) : strSize(strlen(strptr)) {
		if(this->strSize < 16) {
			//< 16 chars store in array.
			// Will take shorter than heap allocation.
			memcpy(&(this->str[0]), strptr, this->strSize + 1);
			this->strBeg = NULL;
		} else {
			//> 16 chars allocate on heap.
			// Will take longer than local storage.
			this->strBeg = new char[this->strSize + 1];
			memcpy(this->strBeg, strptr, this->strSize + 1);
		}
	}

	char* begin() { return this->strSize < 16 ? &(this->str[0]) : this->strBeg; }

	char* end() { return begin() + this->strSize; }

	size_t length() const { return this->strSize; }

	~SSOString() {
		if(this->strBeg) {
			delete[] this->strBeg;
		}
	}

private:
	size_t strSize;
	char* strBeg;
	char str[16];
};

int main(int argc, char* argv[]) {
	// Create referenced object.
	ReferencedObject<SSOString> ref(new SSOString("Hello World!!")); // 13 chars

	ReferencedObject<SSOString> ref16(
	  new SSOString("This string is over 16 characters long so allocated on Heap")); // 13 chars

	// Invocation access
	cout << "ref value is " << ref->begin() << " with size " << ref->length() << "\n\n";

	cout << "ref16 value is " << ref16->begin() << " with size " << ref16->length() << "\n\n"
	     << flush;

	ReferencedObject<SSOString> refCopy(
	  new SSOString()); // = ref;  // (new SSOString("Hello World!!")); //13 chars
	refCopy = ref;

	ReferencedObject<SSOString> ref16Copy(new SSOString()); // = ref16;
	ref16Copy = ref16;

	cout << "refCopy value is " << refCopy->begin() << "\n\n" << flush;

	cout << "ref16Copy value is " << ref16Copy->begin() << "\n\n" << flush;

	return 0;
}