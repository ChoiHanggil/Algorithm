
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
	int n; 
	cin >> n;
	vector<string> ret;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		string temp;
		bool zero = false;

		for (int j = 0; j <= s.size(); j++)
		{
			if (j < s.size() && isdigit(s[j]))
			{

				if (s[j] == '0' && temp.empty())
				{
					zero = true;
				}	
				else
				{
					temp += s[j];
					zero = false;
				}
			}
			else
			{
				if (zero == true)
				{
					ret.push_back("0");
					zero = false;
				}
				if (temp.size())
				{
					ret.push_back(temp);
					temp.clear();
				}
				
			}
		}
	}

	std::sort(ret.begin(), ret.end(), 
		[](const string& a, const string& b) 
		{
			if (a.size() != b.size())
				return a.size() < b.size();
			return a < b;
		});


	for (auto &num : ret)
	{
		cout << num << endl;
	}
	
}


