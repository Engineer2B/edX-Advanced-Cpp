#include "../../Common/Referenced_Object.hpp"

#include <string>

using namespace std;

int main(int argc, char* argv[]){
	// Create referenced object.
	ReferencedObject<SharedObject> ref(new SharedObject());

	//Invocation access
	ref->SharedObjectAccess("Hello World !!!");

	cout << "\n\n copying ref will increase counter \n\n" << flush;

	ReferencedObject<SharedObject> ref2(new SharedObject());

	ref2 = ref;

	//Invocation access
	ref2->SharedObjectAccess("Hello from ref2");
	cout << "\n\n" << flush;

	//Indirection access
	cout << "ref val is " << (*ref).getVal() << "\n\n" << flush;
}