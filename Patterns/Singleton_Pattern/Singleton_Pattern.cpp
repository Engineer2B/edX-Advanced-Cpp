#include <iostream>
#include <string>

using namespace std;

class Singleton {
public:
	static Singleton* getSingleton() {
		if(!Singleton::instance) { // Only allow one instance of class to be generated.
			Singleton::instance = new Singleton;
		}
		return Singleton::instance;
	}

	void sayHello(string str) { cout << "Hello from singleton \n" << str; }

private:
	Singleton() {} // Private so cannot be invoked.
	Singleton& operator=(Singleton const& rhs) {} // Private so cannot be invoked.
	Singleton(Singleton const&){};
	static Singleton* instance;
};

// Create 1 instance;
Singleton* Singleton::instance = NULL;

int main(int argc, char* argv[]) {
	// Get instance create single object.
	Singleton::getSingleton()->sayHello("Hello world!!! \n");

	return 0;
}
