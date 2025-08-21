
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
	string s;
	while (s != "end")
	{
		cin >> s;
		if (s == "end")
		{
			break;
		}
		queue<char> q;
		for (auto c : s)
		{
			q.push(c);
		}
		char temp1 = '*';
		char flag = false;
		int cnt1 = 0, cnt2 = 0;
		while (!q.empty())
		{
			char f = q.front();
			q.pop();
			if (f == 'a' || f == 'e' || f == 'i' || f == 'o' || f == 'u')
			{
				flag = true;
				cnt1++;
				cnt2 = 0;
			}
			else
			{
				cnt1 = 0;
				cnt2++;
			}
			if (cnt1 > 2 || cnt2 > 2)
			{
				flag = false;
				break;
			}
			if (temp1 == f)
			{
				if (f != 'e' && f != 'o' )
				{
					flag = false;
					break;
				}
			}
			temp1 = f;
		}

		if (flag == true)
		{
			cout << "<" << s << ">" << " is acceptable."<<endl;
		}
		else
		{
			cout << "<" << s << ">" << " is not acceptable." << endl;
		}
		while (!q.empty())
		{
			q.pop();
		}
	}

}


