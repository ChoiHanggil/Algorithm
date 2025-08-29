
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
	
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		if (s[0] == ')' || s.size()&1)
		{
			cout << "NO" << '\n';
			continue;
		}
		stack<char> st;
		for (auto c : s)
		{
			if (c == ')'&& !st.empty() && st.top() == '(')
			{
				st.pop();
			}else
			{
				st.push(c);
			}
		}

		if (st.empty())
		{
			cout << "YES" << '\n';
		}
		else
		{
			cout << "NO" << '\n';
		}
	}
	
}


