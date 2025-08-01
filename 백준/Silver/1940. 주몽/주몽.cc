#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int n, m, a;
	cin >> n >> m;
	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		v.push_back(a);
	}
	int answer = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (v[i] + v[j] == m)
			{
				v[i] = 10000001;
				v[j] = 10000001;
				answer++;
			}
		} 
	}
	cout << answer << endl;
}
