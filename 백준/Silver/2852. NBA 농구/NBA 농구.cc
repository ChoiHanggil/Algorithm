
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
	vector<pair<int,int>> goal;

	for (int i = 0; i < n; i++)
	{
		int team;
		string s;
		cin >> team >> s;

		int mnt = stoi(s.substr(0, s.find(':')));
		int scd = stoi(s.substr(s.find(':') + 1));

		goal.push_back({ team, mnt * 60 + scd });

	}

	vector<int> v(48 * 60, 0);
	int g = 0;
	int t = goal[g].second;
	int cnt1 = 0, cnt2 = 0;

	if (goal[g].first == 1)
	{
		cnt1++;
	}
	else
	{
		cnt2++;
	}
	int ret1 = 0, ret2 = 0;
	while (t < 48 * 60)
	{
		if (cnt1 > cnt2)
		{
			ret1++;
		}
		else if (cnt1 < cnt2)
		{
			ret2++;
		}

		t++;
		if (g+1 < goal.size() && t == goal[g + 1].second)
		{
			g++;
			if (goal[g].first == 1)
			{
				cnt1++;
			}
			else
			{
				cnt2++;
			}
		}
	}
	
	cout << setw(2) << setfill('0') << ret1 / 60 << ":" << setw(2) << setfill('0') << ret1 % 60 << '\n';
	cout << setw(2) << setfill('0') <<  ret2 / 60 << ":" << setw(2) << setfill('0') << ret2 % 60 << '\n';
	
}


