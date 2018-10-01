#include <forward_list>
#include <iostream>
#include <istream>
#include <iterator>
#include <list>
#include <string>
#include <vector>

using namespace std;

int main() {
	// istreambuf demo.
	istreambuf_iterator<char> isbeos;
	istreambuf_iterator<char> isbuf(cin.rdbuf());
	string mystring;

	cout << "Please enter some text and the return key when finished: ";

	while(isbuf != isbeos && *isbuf != '\n') {
		mystring += *isbuf++;
	}

	cout << "\n"
	     << "The text you entered was " << mystring.c_str() << ".\n\n";

	// istream example
	int val1, val2;
	cout << "Please enter two integers: ";

	istream_iterator<int> iseos; // end-of-stream iterator
	istream_iterator<int> is(cin); // stin iterator

	if(is != iseos && *is != '\n') {
		val1 = *is;
	}

	++is;
	if(is != iseos && *is != '\n') {
		val2 = *is;
	}

	cout << "\n"
	     << "You entered values: " << val1 << " and " << val2 << "\n\n";

	// forward iterator
	forward_list<int> fwdlist;
	forward_list<int>::iterator fwdlistiter;
	fwdlist.push_front(3);
	fwdlist.push_front(2);
	fwdlist.push_front(1);

	cout << "Forward iterator traversal of forward_list." << endl;
	for(fwdlistiter = fwdlist.begin(); fwdlistiter != fwdlist.end(); fwdlistiter++) {
		cout << (*fwdlistiter) << endl;
	}

	cout << "\n";

	// Create vector and list for iterator examples.
	vector<int> v;
	vector<int>::iterator iter;

	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	list<int> li;
	list<int>::iterator listiter;
	list<int>::reverse_iterator revlistiter;
	li.push_back(1);
	li.push_back(2);
	li.push_back(3);

	// Bi directional iterator example
	// Forward traversal
	cout << "Forward traversal of list." << endl;
	for(listiter = li.begin(); listiter != li.end(); listiter++) {
		cout << (*listiter) << endl;
	}

	cout << "\n";

	// Reverse traversal.
	cout << "Reverse traversal of list." << endl;
	for(revlistiter = li.rbegin(); revlistiter != li.rend(); revlistiter++) {
		cout << (*revlistiter) << endl;
	}

	cout << "\n";

	iter = v.begin();
	iter += 2;
	cout << "Random Access iterator vector beginning + offset 2 is " << *iter << "\n" << endl;

	// Iterate array of ints with a pointer.
	cout << "Traverse int array with pointer " << endl;
	int intarray[3];
	intarray[0] = 1;
	intarray[1] = 2;
	intarray[2] = 3;
	int* endintarray = intarray + 3;
	for(int* ptr = intarray; ptr < endintarray; ptr += 1) {
		cout << *ptr << endl;
	}

	cout << "\n";

	return 0;
}