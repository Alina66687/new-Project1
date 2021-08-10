#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> arr2;
	for (int i = 100; i > 0; i--)
	{
		arr2.push_back(i);
	}
	arr2.insert(arr2.begin() + 4, 77);
	for (auto i : arr2)
	{
		cout << i << " ";
	}
}