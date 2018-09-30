#include <iostream>

using namespace std;

template<class point>
class Point {
	public:

		Point() {}
		Point(point x, point y) : px(x), py(y) {
			cout << "Point object constructor." << endl;
		}

		void printPoint() {
			cout << " X " << px << " Y " << py << endl;
		}

	private:
		point px;
		point py;

};

template<class derPoint>
class Point3D : Point<derPoint> {
	public:
		Point3D(derPoint x, derPoint y, derPoint z) : px(x), py(y), pz(z) {
			cout << "Point3D object constructor." << endl;
		}

		void printPoint() {
			cout << " X " << px << " Y " << py << " Z " << pz << endl;
		}

	private:
		derPoint px;
		derPoint py;
		derPoint pz;

};

int main() {

	Point<int> basePoint(5,5);
	Point3D<double> derivedPoint(99.9,99.9,99.9);

	cout << "basePoint is "; 
	basePoint.printPoint();

	cout << "derivedPoint is ";
	derivedPoint.printPoint();

	return 0;

}