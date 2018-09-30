#include <iostream>

using namespace std;

class Cat {
public:
	void makeCatMeow() {
		cout << catnoise.c_str() << endl;
	}
private:
	string catnoise = "meow meow";
};

class Dog {
	public:
		void makeDogBark() {
			cout << dognoise.c_str() << endl;
		}
		private:
		string dognoise = "wof wof";
};

class Horse {
	public:
	void makeHorseNay() {
		cout << horsenoise.c_str() << endl;
	}
	private:
	string horsenoise = "nay nay";
};

class Frog {
	public:
	void makeFrogCroak() {
		cout << frognoise.c_str() << endl;
	}
	private:
	string frognoise = "croak croak";
};

class AnimalInterface {
public:
	//Destructor
	virtual ~AnimalInterface() {}
	//Pure virtual execute function has to be implemented by derived classes.
	virtual void execute() = 0;
};

template <class T>
class AnimalAdapter : public AnimalInterface {
public:
	//Constructor
	AnimalAdapter(T *o, void(T:: *m)()) {
		animalObject = o;
		animalfunction = m;
	}
	//Deconstructor.
	~AnimalAdapter() {
		delete animalObject;
	}
	//Implement AnimalInterface pure virtual function.
	void execute() {
		(animalObject->*animalfunction)();
	}
private:
	//Members to hold object and function pointers
	T *animalObject;
	void(T:: *animalfunction)();
};

int main(){
	//Cat
	AnimalAdapter<Cat> catO(new Cat(), &Cat::makeCatMeow);
	catO.execute();

	//Dog
	AnimalAdapter<Dog> dogO(new Dog(), &Dog::makeDogBark);
	dogO.execute();

	//Horse
	AnimalAdapter<Horse> horseO(new Horse(), &Horse::makeHorseNay);
	horseO.execute();

	//Frog
	AnimalAdapter<Frog> frogO(new Frog(), &Frog::makeFrogCroak);
	frogO.execute();

	return 0;
}