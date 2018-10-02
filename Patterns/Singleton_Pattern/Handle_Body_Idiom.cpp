#include <iostream>
#include <string>

using namespace std;

class Body {
public:
	Body() : str("") {}

	void printBody() { cout << "printBody called. \n"; }

	void updateTxt(string s) { this->str = s; }

	void printTxt() { cout << this->str << "\n"; }

private:
	string str;
};

class Handle {
public:
	Handle() : bdy(new Body()) {}

	void handleBody(string ss) {
		this->bdy->printBody();
		this->bdy->updateTxt(ss);
		this->bdy->printTxt();
	}

	~Handle() {
		if(this->bdy) {
			delete this->bdy;
		}
	}

private:
	Body* bdy;
};

int main(int argc, char* argv[]) {
	Handle hand;
	hand.handleBody("Main function call.");

	return 0;
}
