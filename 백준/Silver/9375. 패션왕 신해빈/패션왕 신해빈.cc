#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include<string>
using namespace std;

int main()
{
	int c, n;
	cin >> c;
	string s1;
	vector<int> answer;
	for (int i = 0; i < c; i++)
	{
		cin >> n;
		unordered_map<string, int> m;
		int cnt = 1;
		for (int j = 0; j < n; j++)
		{
			cin.ignore();
			getline(cin, s1);
			m[s1.substr(s1.find(" "))]++;
		}
		for (auto& e : m)
		{
			cnt *= (e.second+1);
		}

		answer.push_back(cnt-1);
	}

	for (auto a : answer)
	{
		cout << a << endl;
	}

}
