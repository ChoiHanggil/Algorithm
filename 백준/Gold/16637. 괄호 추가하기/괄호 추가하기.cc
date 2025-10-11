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

//int dx[4] = { -1, 0, 1, 0 };
//int dy[4] = { 0, 1, 0, -1 };

using namespace std;

int ret = INT_MIN;
int Sum(vector<char>& ns, vector<int>& comb, vector<int>& nums)
{
	vector<char> tns(ns);
	vector<int> tnums(nums);
	vector<int> sComb = comb;
	sort(sComb.rbegin(), sComb.rend());
	for (int i = 0; i < sComb.size(); i++)
	{
		if (tns[sComb[i]] == '+')
		{
			tnums[sComb[i]] += tnums[sComb[i] + 1];
		}
		else if (tns[sComb[i]] == '-')
		{
			tnums[sComb[i]] -= tnums[sComb[i] + 1];
		}
		else if (tns[sComb[i]] == '*')
		{
			tnums[sComb[i]] *= tnums[sComb[i] + 1];
		}
		tnums.erase(tnums.begin() + sComb[i] + 1);
		tns.erase(tns.begin() + sComb[i]);
	}
	int sum = tnums[0];
	for (int j = 0; j < tns.size(); j++)
	{
		if (tns[j] == '+')
		{
			sum += tnums[j + 1];
		}
		else if (tns[j] == '-')
		{
			sum -= tnums[j + 1];
		}
		else if (tns[j] == '*')
		{
			sum *= tnums[j + 1];
		}
	}

	return sum;
}


void Combination(vector<char>& ns, int start, int r, vector<int>& comb, vector<int>& nums)
{
	if(comb.size() == r)
	{
		ret = max(ret ,Sum(ns, comb, nums));
		return;
	}
	for (int i = start; i < ns.size(); i++)
	{
		comb.push_back(i);
		Combination(ns, i + 2, r, comb, nums);
		comb.pop_back();
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> nums;
	vector<char> ns;
	string s;
	cin >> s;
	int cnt = 0;
	if (n == 1)
	{
		cout << s[0] - '0';
		return 0;
	}

	for (int i = 0; i < n; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			nums.push_back(s[i] - '0');
		}
		else
		{
			ns.push_back(s[i]);
		}
	}
	

	int p = (nums.size()+1-1) / 2;
	
	vector<int> comb;

	for (int i = 0; i <= p; i++)	
	{
		Combination(ns, 0, i, comb, nums);
	}

	cout << ret;
}