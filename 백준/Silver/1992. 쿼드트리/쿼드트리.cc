#include <iostream>
#include <vector>
//#include <map>
//#include <unordered_map>
//#include<string>
//#include<algorithm>
//#include<stack>
//#include<queue>
//#include<cmath>
#include <limits>
//#include <unordered_set>

using namespace std;

string quard(vector<vector<char>> grid, int x, int y, int n)
{
	if (n == 1)
	{
		return string(1, grid[x][y]);
	}
	char a = grid[x][y];
	string ret = "";
	bool flag = false;
	for (int i = x; i < x + n; i++)
	{
		for (int j = y; j < y + n; j++)
		{
			if (a != grid[i][j])
			{
				ret += '(';
				ret += quard(grid, x, y, n / 2);
				ret += quard(grid, x, y+n/2, n / 2);
				ret += quard(grid, x+n/2, y, n / 2);
				ret += quard(grid, x+ n/2, y+n/2, n / 2);
				ret += ')';
				return ret;
			}
		}
	}
	return string(1, grid[x][y]);
}

int main()
{
	int n;
	cin >> n;
	string s;
	vector<vector<char>> grid(n);
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		for (auto c : s)
		{
			grid[i].push_back(c);
		}
	}

	cout << quard(grid, 0, 0, n);

}

