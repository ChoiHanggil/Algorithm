#include <iostream>
#include<algorithm>
#include <vector>
#include <string>


using namespace std;

int main()
{
	string s;
	getline(cin, s);

	string answer;
	int temp;
	for (auto c : s)
	{
		temp = c + 13;
		if ((c >= 97 && c <= 122))
		{
			if ( temp > 122)
			{
				answer += (temp - 26);
			}
			else
			{
				answer += temp;
			}
		}
		else if (c >= 65 && c <= 90)
		{
			if (temp > 90)
			{
				answer += (temp - 26);
			}
			else
			{
				answer += temp;
			}
		}
		else
		{
			answer += c;
		}
	}

	cout << answer;
}

