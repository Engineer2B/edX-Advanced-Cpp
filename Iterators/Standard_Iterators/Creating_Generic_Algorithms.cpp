#include "../../Common/Generic_Algorithms.hpp"

int main(int argc, char *argv[])
{

	//Containers used as to apply algorithms to.
	std::forward_list<int> firstList = {34, 77, 16, 2};
	std::forward_list<int> secondList = {35, 76, 18, 2};

	std::list<int> List = {34, 77, 16, 2, 35, 76, 18, 2};

	std::vector<int> resultsList(8);

	//Sort containers.
	firstList.sort();
	secondList.sort();

	//Find first instance example.
	cout << "findfirstinstance of 16 in firstList and 76 in secondlist is " << *findfirstinstance(firstList.begin(), firstList.end(), 16) << " " << *findfirstinstance(secondList.begin(), secondList.end(), 76) << "\n";
	cout << "\n";

	//mergeSortedContainers example.
	cout << "Results of calling mergeSortedContainers with firstList and secondList are."
			 << "\n";
	mergeSortedContainers(firstList.begin(), firstList.end(), secondList.begin(), secondList.end(), resultsList.begin());

	for (std::vector<int>::iterator it = resultsList.begin(); it != resultsList.end(); it++)
	{
		cout << *it << " ";
	}
	cout << "\n\n";

	//findandreplace example.
	cout << "Results of calling findandreplace on firstList with values 16 and 23"
			 << "\n";
	findandreplace(firstList.begin(), firstList.end(), 16, 23);
	for (std::forward_list<int>::iterator it = firstList.begin(); it != firstList.end(); it++)
	{
		cout << *it << " ";
	}
	cout << "\n\n";

	cout << "Results of calling findandreplace on secondList with values 76 and 1006"
			 << "\n";
	findandreplace(secondList.begin(), secondList.end(), 76, 1006);
	for (std::forward_list<int>::iterator it = secondList.begin(); it != secondList.end(); it++)
	{
		cout << *it << " ";
	}
	cout << "\n\n";

	//reverseCopy example.
	cout << "Results of calling reverseCopy on firstList is "
			 << "\n";
	resultsList.empty();
	resultsList.resize(List.size());
	reverseCopy(List.begin(), List.end(), resultsList.begin());
	for (std::vector<int>::iterator it = resultsList.begin(); it != resultsList.end(); it++)
	{
		cout << *it << " ";
	}
	cout << "\n\n";

	//randomise example.
	cout << "Calling randomise on sorted vector "
			 << "\n";
	List.sort();
	std::vector<int> temp(List.begin(), List.end());
	for (std::vector<int>::iterator it = temp.begin(); it != temp.end(); it++)
	{
		cout << *it << " ";
	}
	cout << "\n\n";

	cout << "Results after calling randomise on sorted vector are "
			 << "\n";
	randomise(temp.begin(), temp.end());
	for (std::vector<int>::iterator it = temp.begin(); it != temp.end(); it++)
	{
		cout << *it << " ";
	}
	cout << "\n\n";
};