#include <iostream>
#include<algorithm>
#include <vector>
using namespace std;

int main()
{
	string s;
	cin >> s;

	vector<int> word(26, 0);

	for (auto e : s)
	{
		if (e >= 97 && e <= 122)
		{
			word[static_cast<int>(e) - 97]++;
		}
	}

	for (auto e : word)
	{
		cout << e << " ";
	}

}

