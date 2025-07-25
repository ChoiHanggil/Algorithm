#include <iostream>
#include<algorithm>
#include <vector>
#include <string>


using namespace std;

int main()
{
	int cnt;
	string a;
	cin >> cnt;
	cin.ignore();
	getline(cin, a);
	
	vector<string> s(cnt);
	for (int i = 0; i < cnt; i++)
	{
		cin >> s[i];
	}
	
	string Begin = a.substr(0, a.find('*'));
	string End = a.substr(a.find('*')+1);

	

	vector<string> answer;
	for (auto e : s)
	{ 
		if (e.size() >= Begin.size() + End.size())
		{
			string front = e.substr(0, Begin.size());
			string back = e.substr(e.size() - End.size());

			if (front == Begin && back == End)
			{
				answer.push_back("DA");
			}
			else
			{
				answer.push_back("NE");
			}
		}
		else
		{
			answer.push_back("NE");
		}
	}

	for (auto e : answer)
	{
		cout << e << endl;
	}
}

