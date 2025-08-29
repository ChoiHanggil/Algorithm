
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

	string s;
	while(1)
	{
		if (!getline(cin, s))
		{
			break;
		}
		if (s == ".") break;
		
		stack<char> st;
		for (char c : s)
		{
			if (c == '(' || c == '[')
			{
				st.push(c);
			}
			else if (c == ')')
			{
				if (!st.empty() && st.top() == '(')
				{
					st.pop();
				}
				else
				{
					st.push(c);

				}
			}
			else if (c == ']')
			{
				if (!st.empty() && st.top() == '[')
				{
					st.pop();
				}
				else
				{
					st.push(c);

				}
			}
		}

		if (st.empty())
		{
			cout << "yes" << '\n';
		}
		else
		{
			cout << "no" << '\n';
		}
	}
	
}


