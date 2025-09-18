#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include<string>
#include<algorithm>
#include<stack>
#include<queue>
#include<cmath>
#include <limits>
#include <unordered_set>
#include <iomanip>
#include <climits>

using namespace std;

int Distance(pair<int, int> home, vector<pair<int, int>> store)
{
	int mn = INT_MAX;
	for (auto& e : store)
	{
		mn = min(mn, abs(home.first - e.first) + abs(home.second - e.second));
	}

	return mn;
}

void combine(vector<pair<int, int>>& store, int m, int start, vector<pair<int, int>>& temp, vector<pair<int, int>>& home, int& sum)
{
	if (temp.size() == m)
	{
		int s = 0;
		for (auto& e : home)
		{
			s += Distance(e, temp);
		}

		sum = min(s, sum);
		
	}
	for (int i = start; i < store.size(); i++)
	{
		temp.push_back(store[i]);
		combine(store, m, i + 1, temp, home, sum);
		temp.pop_back();
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
	cin >> n >> m;
	
	vector<pair<int, int>> home;
	vector<pair<int, int>> store;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int a;
			cin >> a;
			if (a == 1)
			{
				home.push_back({ i,j });
			}
			else if (a == 2)
			{
				store.push_back({ i,j });
			}
		}
	}

	int sum = 0;

	if (store.size() == m)
	{
		for (auto& e : home)
		{
			sum += Distance(e, store);

		}
	}
	else
	{
		vector<pair<int, int>> temp;
		sum = INT_MAX;
		combine(store, m, 0, temp, home, sum);
	}
	
	cout << sum;
}