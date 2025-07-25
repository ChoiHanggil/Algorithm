#include <iostream>
#include<algorithm>
#include <vector>

using namespace std;

int main()
{
	int num;
	cin >> num;
	
	vector<int> names(26, 0);
	string name;

	for (int i = 0; i < num; i++)
	{
		cin >> name;
		names[name[0] - 'a']++;
	}

	string answer;

	for (int i = 0; i < 26; i++)
	{
		if (names[i] >= 5)
		{
			answer += 'a' + i;
		}
	}
	if (answer.size() == 0)
	{
		answer = "PREDAJA";
	}

	cout << answer;
}

