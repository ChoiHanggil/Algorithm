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

using namespace std;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	
	int n;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; i++)
	{
		cin >> nums[i];
	}

	vector<int> ret(n, -1);
	stack<int> s;

	for (int i = 0; i < n; i++)
	{
		while (!s.empty() && nums[s.top()] < nums[i])
		{
			ret[s.top()] = nums[i];
			s.pop();
		}
		s.push(i);
	}
	
	for (int x : ret)
	{
		cout << x << " ";
	}

}