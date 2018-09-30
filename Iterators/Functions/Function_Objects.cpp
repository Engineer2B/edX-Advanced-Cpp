#include "../../Common/Generic_Algorithms.hpp"
#include <algorithm>

using namespace std;

struct sortedStruct
{
	int val;

	sortedStruct(int k) : val(k) {}

	bool operator < (const sortedStruct& rhs) const
	{
		return (val < rhs.val);
	}
};

class sortedClass
{
public:
	sortedClass(int x) :val(x) {}
	~sortedClass() {};
	int getVal() const { return val; }
	bool operator < (const sortedClass& sc) const { 
		return val < sc.getVal(); 
	}
private:
	int val;
};

class lessThan {
public:
	lessThan() {};
	~lessThan() {};
	bool operator()(const sortedClass& lhs, const sortedClass& rhs) const { 
		return lhs < rhs; 
	};
	bool operator()(const sortedStruct& lhs, const sortedStruct& rhs) const {
		return lhs < rhs;
	};
};


class greaterThan {
public:
	greaterThan(int cmp): X(cmp) {};
	~greaterThan() {};
	bool operator()(const sortedClass& z) const { return z.getVal() > X; } //> comparison
	bool operator()(const sortedStruct& z) const { return z.val > X; } //> comparison
private:
	int X;
};

int main(int argc, char* argv[]) {

	vector<sortedClass> vecSortClas;
	vector<sortedStruct> vecSortStru;
	for (int i = 0; i < 50; i++) {
		sortedClass sc(i);
		sortedStruct ss(i);
		vecSortClas.push_back(sc);
		vecSortStru.push_back(ss);
	}

	randomise(vecSortClas.begin(),vecSortClas.end());

	randomise(vecSortStru.begin(), vecSortStru.end());

	//Sorted Class

	cout << "Vector of sortedClass classes before sorting is " << "\n\n";

	for (vector<sortedClass>::iterator it = vecSortClas.begin(); it != vecSortClas.end(); it++) {
		cout << "sortedClass index " << distance(vecSortClas.begin(),it) << " has value " << it->getVal() << "\n";
	}

	std::sort(vecSortClas.begin(),vecSortClas.end(),lessThan());

	cout << "\n\n" << "Vector of sortedClass classes after sorting is " << "\n\n";

	for (vector<sortedClass>::iterator it = vecSortClas.begin(); it != vecSortClas.end(); it++) {
		cout << "sortedClass index " << distance(vecSortClas.begin(), it) << " has value " << it->getVal() << "\n";
	}

	cout << "\n\n";

	//SortedStruct
	cout << "Vector of sortedStruct Structs before sorting is " << "\n\n";

	for (vector<sortedStruct>::iterator it = vecSortStru.begin(); it != vecSortStru.end(); it++) {
		cout << "sortedClass index " << distance(vecSortStru.begin(), it) << " has value " << it->val << "\n";
	}

	std::sort(vecSortStru.begin(), vecSortStru.end(), lessThan());

	cout << "\n\n" << "Vector of sortedStruct structs after sorting is " << "\n\n";

	for (vector<sortedStruct>::iterator it = vecSortStru.begin(); it != vecSortStru.end(); it++) {
		cout << "sortedClass index " << distance(vecSortStru.begin(), it) << " has value " << it->val << "\n";
	}

	cout << "\n\n" << "Vector of sortedStruct structs which are greater than 45 " << "\n\n";

	for (vector<sortedStruct>::iterator it = vecSortStru.begin(); it != vecSortStru.end(); it++) {
		vector<sortedStruct>::iterator it2 = it;
		auto ittemp = find_if(it2, it2+1, greaterThan(45));
		if (ittemp != it2+1) {
			cout << "sortedClass index " << distance(vecSortStru.begin(), it) << " is greater than 45 " << ittemp->val << "\n";
		}
	}

	//Destroy elements.
	vecSortClas.empty();
	vecSortStru.empty();

	return 0;
}
