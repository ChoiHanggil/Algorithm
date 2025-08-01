#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	string s;
	cin >> s;

	vector<int> cnt(26, 0);
	for (int i = 0; i < s.size(); i++)
	{
		cnt[s[i] - 65]++;
	}
	int odd = 0;
	for (int i = 0; i < 26; i++)
	{
		if ((cnt[i] & 1) != 0)
		{
			odd++;
		}
	}
	string s2;
	char temp = '*';
	if (odd > 1)
	{
		cout << "I'm Sorry Hansoo" << endl;
	}
	else
	{
		for (int i = 0; i < 26; i++)
		{
			if (cnt[i] % 2 != 0)
			{
				temp = i+65;
			}
			for (int j = 0; j < cnt[i] / 2; j++)
			{
				s2 += (i+65);
			}
		}
		if (temp != '*')
		{
			s2 += temp;
		}
		string answer = s2;
		reverse(s2.begin(), s2.end());
		if (s2.find(temp) != string::npos)
		{
			s2 = s2.substr(1);
		}
		answer += s2;

		cout << answer << endl;
	}
	

}
