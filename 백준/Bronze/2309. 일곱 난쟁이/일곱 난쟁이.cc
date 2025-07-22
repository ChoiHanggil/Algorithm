#include <iostream>
#include<algorithm>
#include <vector>
using namespace std;

int main()
{
	vector<int> dwarf;
	int height, Sum{};
	for (int i = 0; i < 9; i++)
	{
		cin >> height;
		Sum += height;
		dwarf.push_back(height);
	}

	int answer;
	bool Loop = false;
	for (int i = 0; i < 9 && !Loop; i++)
	{
		for (int j = i + 1; j < 9; j++)
		{
			answer = Sum - dwarf[i] - dwarf[j];
			if (answer == 100)
			{
				dwarf.erase(dwarf.begin() + i);
				dwarf.erase(dwarf.begin() + j - 1);
				Loop = true;
				break;
			}
		}
	}

	sort(dwarf.begin(), dwarf.end());

	for (auto e : dwarf)
	{
		cout << e << endl;
	}
}

