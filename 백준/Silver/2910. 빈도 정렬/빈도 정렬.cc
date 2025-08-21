
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include<string>
#include<algorithm>
#include<stack>
#include<queue>
#include<cmath>
#include <limits>
#include <unordered_set>

using namespace std;

int main()
{
	int n, c;
	cin >> n >> c;

	unordered_map<int, pair<int, int>> m;
	vector<int> order;

	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		if (m.find(a) == m.end())
		{
			m[a] = { 1, i };
			order.push_back(a);
		}
		else
		{
			m[a].first++;
		}
	}

	vector<pair<int, pair<int, int>>> v;
	for (auto e : m)
	{
		v.push_back({ e.first, {e.second.first, e.second.second} });
	}

	sort(v.begin(), v.end(), [](const auto& a, const auto& b) 
		{ if(a.second.first != b.second.first) return a.second.first > b.second.first;
		return a.second.second < b.second.second;
		});

	for (auto e : v)
	{
		int key = e.first;
		int cnt = e.second.first;

		for (int i = 0; i < cnt; i++)
		{
			cout << key << " ";
		}
	}
}


