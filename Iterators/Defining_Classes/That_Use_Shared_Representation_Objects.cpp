#include "../../Common/Referenced_Object.hpp"

using namespace std;

int main(int argc, char* argv[]) {
	// Create referenced object.
	ReferencedObject<SharedObject> ref(new SharedObject());

	// Invocation access
	ref->SharedObjectAccess("Hello World !!!");

	cout << "copying ref will increase counter \n";

	ReferencedObject<SharedObject> ref2(new SharedObject());
	ref2 = ref;

	// Invocation access
	ref2->SharedObjectAccess("Hello from ref2");

	cout << "\n\n";
	// Indirection access
	cout << "ref val called via indirection operator is " << (*ref).getVal() << "\n\n";

	return 0;
}