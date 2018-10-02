#include <iostream>
#include <string>

using namespace std;

class Enclosing {
public:
	Enclosing() : nested(new Nested()) { enclosingInt = rand(); }
	void printEnclosing() { nested->printNested(this); }

	~Enclosing() {
		if(this->nested) {
			delete this->nested;
		}
	}

private:
	class Nested {
	public:
		Nested() {
			this->var1 = rand();
			this->var2 = "Hello from Nested.";
		}
		void printNested(Enclosing* enc) {
			cout << "Enclosing int var is " << enc->enclosingInt << "\n";
			cout << "Nested var1 is " << this->var1 << " Nested var2 is " << this->var2 << "\n";
		}

	private:
		int var1;
		string var2;
	};

private:
	Nested* nested;
	int enclosingInt;
};

int main(int argc, char* argv[]) {
	Enclosing en;
	en.printEnclosing();

	return 0;
}
