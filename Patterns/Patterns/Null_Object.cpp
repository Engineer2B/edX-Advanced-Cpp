#include <iostream>
#include <vector>

using namespace std;

class hardwareInterface {
public:
	virtual void doSomething() = 0;
	virtual vector<string>* getUsers() = 0;
};

class nullObject : public hardwareInterface {
public:
	void doSomething() {}

	vector<string>* getUsers() { return &(this->usr); }

private:
	vector<string> usr;
};

int main(int argc, char* argv[]) {
	nullObject no;

	no.doSomething();

	vector<string>* vecPtr;
	vecPtr = no.getUsers();

	cout << "Vector users has size " << vecPtr->size() << " so nothing to iterate over\n";

	for(vector<string>::iterator it = vecPtr->begin(); it != vecPtr->end(); it++) {
		cout << "Vector is not empty.  \n";
	}

	return 0;
}
