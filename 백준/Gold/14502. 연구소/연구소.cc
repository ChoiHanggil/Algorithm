
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

int SearchCnt(vector<vector<int>>& grid)
{
	int dx[4] = {-1, 0, 1, 0};
	int dy[4] = { 0, 1, 0, -1 };

	for (int i = 0; i < grid.size(); i++)
	{
		for (int j = 0; j < grid[0].size(); j++)
		{
			if (grid[i][j] == 2)
			{		
				queue<pair<int, int>> q;
				q.push({ i,j });
				grid[i][j] = 2;
				while (!q.empty())
				{
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					for (int n = 0; n < 4; n++)
					{
						int nx = x + dx[n];
						int ny = y + dy[n];
						if (nx< 0 || nx >=grid.size() || ny<0 || ny >=grid[0].size()) continue;
						if (grid[nx][ny] == 0)
						{
							q.push({ nx,ny });
							grid[nx][ny] = 2;
						}
					}
				}
			}
		}
	}
	int cnt = 0;
	for(auto r : grid)
		for (auto c : r)
		{
			if (c == 0)
			{
				cnt++;
			}

		}

	return cnt;
}



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> v;
	
	vector<vector<int>> grid(n);
	int a;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a;
			grid[i].push_back(a);
			if (a == 0)
			{
				v.push_back({ i,j });
			}
		}
	}	

	int ret = 0;

	for (int i = 0; i < v.size(); i++) 
	{
		for (int j = i + 1; j < v.size(); j++)
		{
			for (int k = j + 1; k < v.size(); k++)
			{
				vector<vector<int>> temp(grid);
				temp[v[i].first][v[i].second] = 1;
				temp[v[j].first][v[j].second] = 1;
				temp[v[k].first][v[k].second] = 1;
				ret = std::max(ret, SearchCnt(temp));
			}
		}
	}

	cout << ret << '\n';
	
}


