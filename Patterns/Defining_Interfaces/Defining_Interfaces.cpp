#include <iostream>

using namespace std;

template<class type> class Shape {
	// pure virtual function
	virtual type area() = 0;
};

template<class type> class Rectangle : public Shape<type> {
public:
	Rectangle(type wd, type hg) : width(wd), height(hg) {}

	type area() { return (width * height); }

	void setWidth(type wd) { width = wd; }

	void setHeight(type hg) { height = hg; }

private:
	type width, height;
};

template<class type> class Triangle : public Shape<type> {
public:
	Triangle(type ba, type alt) : base(ba), altitude(alt) {}

	type area() { return (base * altitude) / 2; }

	void setBase(type ba) { base = ba; }

	void setAltitude(type alt) { altitude = alt; }

private:
	type base, altitude;
};

template<class type> class Elipse : public Shape<type> {
public:
	Elipse(type minorAxisLen, type majorAxisLen) : minorAxis(minorAxisLen), majorAxis(majorAxisLen) {}

	type area() { return (pi * minorAxis * majorAxis); }

	void setMinorAxis(type ma) { minorAxis = ma; }

	void setMajorAxis(type ma) { majorAxis = ma; }

private:
	type minorAxis, majorAxis;
	const type pi = 3.1415926535897;
};

int main(int argc, char* argv[]) {
	Rectangle<int> rect(5, 5);
	Triangle<float> tri(3.3f, 6.5f);
	Elipse<double> eli(3.3, 7.3);

	// Helper function.
	rect.setWidth(3);

	cout << "Rectangle area is " << rect.area() << "\n" << flush;
	printf("Triangle area is %f \n", tri.area());
	printf("Elipse area is %lf \n", eli.area());

	return 0;
}