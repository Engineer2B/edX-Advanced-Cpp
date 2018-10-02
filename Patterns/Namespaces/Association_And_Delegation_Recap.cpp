#include <iostream>
#include <ctime>

using std::cout;

class LibraryCard {
public:
	LibraryCard() : cardNbr(rand()) {}

	int getCard() { return cardNbr; }

private:
	int cardNbr;
};

class Student {
public:
	Student() : lc(NULL) {}

	~Student() {}

	void setLibraryCard(LibraryCard* llc) { lc = llc; }

	// Association Student class does not control lifecycle of LibraryCard but accesses functions.
	// Delagation Student delagates request to LibraryCard.
	int libraryCardNumber() {
		if(lc) {
			return lc->getCard();
		} else {
			return NULL;
		}
	}

private:
	LibraryCard* lc;
};

int main(int argc, char* argv[]) {
	// Set the random number generator seed s.t. the resulting library card number is not always 41.
	srand(static_cast<unsigned int>(time(NULL)));
	LibraryCard myCard;
	Student me;
	me.setLibraryCard(&myCard);

	cout << "My library card number is " << me.libraryCardNumber() << "\n";

	return 0;
}