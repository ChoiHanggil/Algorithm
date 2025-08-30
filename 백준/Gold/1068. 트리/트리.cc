
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
#include <iomanip>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	int a;
	unordered_map<int, vector<int>> m;
	for (int i = 0; i < n; i++)
	{
		m[i];
		cin >> a;
		if (a == -1) continue;
		m[a].push_back(i);
	}
	int x;
	cin >> x;

	queue<int> child;
	child.push(x);
	while (!child.empty())
	{
		int c = child.front();
		child.pop();
		for (auto e : m[c])
		{
			child.push(e);
		}
		m.erase(c);
	}

	int ret = 0;
	for (auto &p : m)
	{
		bool leaf = true;
		for (auto e : p.second)
		{
			if (m.find(e) != m.end())
			{
				leaf = false;
				break;
			}
		}
		if (leaf) ret++;
	}

	cout << ret;
}


