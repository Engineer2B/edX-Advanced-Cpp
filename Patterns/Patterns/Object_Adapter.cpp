#include <iostream>
#include <string>
#include <vector>

using namespace std;

class vendingMachine1 {
public:
	vendingMachine1() {
		this->name = "vendingMachine1";
		this->soldItems = 5;
	}

	string myName() { return this->name; }

	int itemsSold() { return this->soldItems; }

private:
	string name;
	int soldItems;
};

class vendingMachine2 {
public:
	vendingMachine2() {
		this->na = "vendingMachine2";
		this->soldItems = 55;
	}

	string name() { return this->na; }

	int Sold() { return this->soldItems; }

private:
	string na;
	int soldItems;
};

class vendingMachine3 {
public:
	vendingMachine3() {
		this->name = "vendingMachine3";
		this->soldItems = 105;
	}

	string getName() { return this->name; }

	int getItemsSold() { return this->soldItems; }

private:
	string name;
	int soldItems;
};

// Adaptor interface.
class machineInterface {
public:
	virtual ~machineInterface() {}
	virtual vector<string> getNames() = 0;
	virtual vector<int> getSoldItems() = 0;
};

class machineWrap : public machineInterface {
public:
	// machineWrap() {}

	vector<string> getNames() {
		this->vnames.clear();
		this->vnames.push_back(this->v1.myName());
		this->vnames.push_back(this->v2.name());
		this->vnames.push_back(this->v3.getName());
		return this->vnames;
	}

	vector<int> getSoldItems() {
		this->vsales.clear();
		this->vsales.push_back(this->v1.itemsSold());
		this->vsales.push_back(this->v2.Sold());
		this->vsales.push_back(this->v3.getItemsSold());
		return this->vsales;
	}

private:
	vendingMachine1 v1;
	vendingMachine2 v2;
	vendingMachine3 v3;
	vector<string> vnames;
	vector<int> vsales;
};

int main(int argc, char* argv[]) {
	machineWrap mw;

	vector<string> mn = mw.getNames();
	vector<int> ms = mw.getSoldItems();
	cout << "Vending machine names and amount of sales are.\n";

	vector<int>::iterator salesit = ms.begin();

	for(vector<string>::iterator it = mn.begin(); it != mn.end(); it++) {
		cout << (*it).c_str() << "  has sales " << *salesit << "\n";
		salesit++;
	}

	cout << "\n";

	return 0;
}
