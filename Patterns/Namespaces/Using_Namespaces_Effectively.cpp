#include <iostream>

using std::cout; // using directive instead of using namespace std since only need cout.

// Namespace 1
namespace ABC {

void doABC() { cout << "doABC() \n"; }
} // namespace ABC

// Namespace 2
namespace DEF {

void doDEF() { cout << "doDEF() \n"; }
} // namespace DEF

// Combined namespace
namespace ABCDEF {
using namespace ABC;
using namespace DEF;
} // namespace ABCDEF

// Main function.
int main(int argc, char* argv[]) {
	ABCDEF::doABC();
	ABCDEF::doDEF();

	return 0;
}