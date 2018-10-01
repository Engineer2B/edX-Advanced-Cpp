#pragma once
#include <iostream>

using namespace std;

// Reference counter base class.
class refCounter {
private:
	// The counter.
	int count;

public:
	// Constructor initialis count to 1.
	refCounter() : count(1) {}

	// Increment count variable
	void increaseCount() {
		count++;
		cout << "increaseCount called count is " << count << "\n" << flush;
	}

	// Decrement count variable.
	int decreaseCount() {
		return --count;
		cout << "decreaseCount called count is " << count << "\n" << flush;
	}
};

template<class referencedObject> class ReferencedObject {
private:
	// The object being referenced.
	referencedObject* refObject;

	// Private destructor throws exception.
	void destructor() throw() {
		if(this->refObject != NULL && this->refObject->decreaseCount() == 0) {
			cout << "referenced object pointer being deleted. \n" << flush;
			delete this->refObject;
			this->refObject = NULL;
		}
	}

public:
	// Empty dummy class to throw
	class classToThrow {};

	// Constructor
	ReferencedObject(referencedObject* newObj = NULL) : refObject(newObj) {}

	// Copy constructor
	// Added for Defining Smart Pointers for Garbage Collection but not used afterwards.
	ReferencedObject(const ReferencedObject<referencedObject>& ro): refObject(ro.refObject){
		// and increment the reference count
		this->refObject->increaseCount();
	}

	// Invocation operator
	referencedObject* operator->() {
		if(!this->refObject) {
			throw classToThrow();
		}
		return this->refObject;
	}

	// Indirection operator.
	referencedObject& operator*() {
		if(!this->refObject) {
			throw classToThrow();
		}
		return *(this->refObject);
	}

	ReferencedObject<referencedObject>& operator=(ReferencedObject<referencedObject>& rhs) {
		// Check if same object if so return.
		if(this == &rhs) {
			return *this;
		}

		// Increment reference count.
		if(rhs.refObject) {
			rhs.refObject->increaseCount();
		}

		// Destroy current refObject which decrease reference count.
		this->destructor();

		// Assign new refObject to private member refObject.
		this->refObject = rhs.refObject;

		// Return object.
		return *this;
	}

	// Destructor calls private destructor which can throw exception from delete.
	~ReferencedObject<referencedObject>() {
		cout << "ReferencedObject destructor called \n" << flush;
		this->destructor();
	}
};

class SharedObject : public refCounter {
public:
	SharedObject() { std::cout << "SharedObject created" << std::endl; }

	void SharedObjectAccess(const char* src) {
		cout << "SharedObjectAccess called parameter argument is " << src << "\n";
	}

	~SharedObject() { std::cout << "SharedObject destroyed" << std::endl; }

	int getVal() { return this->val; }

private:
	int val = 7;
};