#include <vector>
#include <iostream>

using namespace std;

template <size_t dimcount, typename T, size_t vecSize>
class multiVector
{
private:
	std::vector<multiVector<dimcount - 1, T, vecSize>> vec;

public:
	multiVector() : vec(vecSize)
	{
		multiVector<dimcount - 1, T, vecSize>();
	}

	const multiVector<dimcount - 1, T, vecSize> &operator[](int m) const
	{
		return vec.at(m);
	}

	multiVector<dimcount - 1, T, vecSize> &operator[](int m)
	{
		return vec.at(m);
	}
};

template <typename T, size_t vecSize>
class multiVector<1, T, vecSize>
{
private:
	std::vector<T> vec;

public:
	multiVector() : vec(vecSize) {}

	T &operator[](const int index)
	{
		return vec[index];
	}

	T &operator[](int m) const
	{
		return vec[m];
	}
};

int main()
{

	vector<vector<vector<int>>> vec; //3 dim vec

	//Fill vectors
	for (int i = 0; i < 5; i++)
	{
		vector<vector<int>> vv;
		for (int j = 0; j < 10; j++)
		{
			vector<int> ve;
			for (int t = 0; t < 3; t++)
			{
				ve.push_back(t);
			}
			vv.push_back(ve);
		}
		vec.push_back(vv);
	}

	//Print contents
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			for (int t = 0; t < 3; t++)
			{
				cout << " element index " << t << " is " << vec[i][j][t] << "\n";
			}
		}
	}

	cout << "\n\n";
	multiVector<4, int, 5> vec4;
	cout << "accessing vec4[1][2][3][4][4] = 7 \n";
	vec4[1][2][3][4] = 7;
	cout << "reading vec4[1][2][3][4][4] is ";
	cout << vec4[1][2][3][4] << "\n";

	//Just to prove good for N dimensions 100*100=10,000 vectors !!!.
	multiVector<4, int, 100> bigVec;

	cout << "\n\n";

	return 0;
}