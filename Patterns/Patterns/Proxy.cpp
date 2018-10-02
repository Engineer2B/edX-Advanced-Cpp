#include <iostream>
#include <string>
#include <time.h>

using namespace std;

class embeddedInterface {
public:
	virtual string getMachineName() = 0;
	virtual int getNumProcesses() = 0;
	virtual void setProcessLevel(int lev) = 0;
	virtual int getProcessLevel() = 0;
};

class embeddedConcrete : public embeddedInterface {
public:
	string getMachineName() { return this->name; }

	int getNumProcesses() { return (rand() % this->processLevel); }

	void setProcessLevel(int lev) { this->processLevel = lev; }

	int getProcessLevel() { return this->processLevel; }

private:
	string name = "XHTRV150";
	int processLevel = 5;
};

class embeddedProxy : public embeddedInterface {
public:
	embeddedProxy() : ec(NULL) {}

	virtual ~embeddedProxy() {
		if(this->ec) {
			delete this->ec;
		}
	}

	string getMachineName() { return getEmbeddedObj()->getMachineName(); }

	int getNumProcesses() { return getEmbeddedObj()->getNumProcesses(); }

	void setProcessLevel(int level) {
		if(level >= 0 && level <= 100) {
			getEmbeddedObj()->setProcessLevel(level);
		}
	}

	int getProcessLevel() { return getEmbeddedObj()->getProcessLevel(); }

private:
	embeddedConcrete* ec;
	embeddedConcrete* getEmbeddedObj(void) {
		if(!this->ec) {
			this->ec = new embeddedConcrete();
		}
		return this->ec;
	}
};

int main(int argc, char* argv[]) {
	embeddedProxy ep;

	cout << "The embedded machine name is " << ep.getMachineName() << "\n\n";

	cout << "The embedded machine has  " << ep.getNumProcesses() << " processes running \n";

	cout << "The embedded machine current proces level is " << ep.getProcessLevel() << "\n";

	ep.setProcessLevel(100);

	cout << "The embedded machine current proces level is " << ep.getProcessLevel() << "\n";

	ep.setProcessLevel(1000);

	cout << "The embedded machine current proces level is " << ep.getProcessLevel() << "\n";

	return 0;
}
