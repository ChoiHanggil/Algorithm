
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

void Move(vector<vector<bool>>& gird, vector<vector<int>>& ret, int x, int y)
{
	int cnt = 0;
	while (y < gird[x].size())
	{
		y++;
		cnt++;
		if (y == gird[x].size() || gird[x][y] == 1)
		{
			break;
		}
		
		ret[x][y] = cnt;
	}

}

int main()
{
	int h, w;
	cin >> h >> w;

	vector<vector<bool>> grid(h);


	for (int i = 0; i < h; i++)
	{
		string s;
		cin >> s;
		for (auto c : s)
		{
			if (c == 'c')
			{
				grid[i].push_back(1);
			}
			else
			{
				grid[i].push_back(0);
			}
		}
	}

	vector<vector<int>> ret(h, vector<int>(w, -1));

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (grid[i][j] == 1)
			{
				ret[i][j] = 0;
				Move(grid, ret, i, j);
			}
		}
	}

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cout << ret[i][j] << " ";
		}
		cout << '\n';
	}
}


