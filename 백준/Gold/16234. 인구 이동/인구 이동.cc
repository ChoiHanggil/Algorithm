#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include<string>
#include<algorithm>
#include<stack>
#include<queue>
#include<cmath>
#include <limits>
#include <unordered_set>
#include <iomanip>
#include <climits>

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

using namespace std;

void BorderOpen(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& visit, int l, int r)
{
	int sum = 0;
	queue<pair<int, int>> q;
	q.push({ i,j });
	visit[i][j] = 1;
	int cnt = 0;
	vector<pair<int, int>> v;
	v.push_back({ i,j });
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		sum += grid[x][y];
		cnt++;
		for (int n = 0; n < 4; n++)
		{
			int nx = x + dx[n];
			int ny = y + dy[n];
			if (nx < 0 || nx >= grid.size() || ny < 0 || ny >= grid.size()) continue;
			if (visit[nx][ny] == false && abs(grid[x][y] - grid[nx][ny]) <= r && abs(grid[x][y] - grid[nx][ny]) >= l)
			{
				q.push({ nx,ny });
				visit[nx][ny] = true;
				v.push_back({ nx,ny });
			}
		}
	}
	for (auto& e : v)
	{
		grid[e.first][e.second] = sum / cnt;
	}
	
}

bool check(vector<vector<int>>& grid, int l, int r)
{
	for (int i = 0; i < grid.size(); i++)
	{
		for (int j = 0; j < grid.size(); j++)
		{
			for (int n = 0; n < 4; n++)
			{
				int nx = i + dx[n];
				int ny = j + dy[n];
				if (nx < 0 || nx >= grid.size() || ny < 0 || ny >= grid.size()) continue;
				if (abs(grid[i][j] - grid[nx][ny]) <= r && abs(grid[i][j] - grid[nx][ny]) >= l)
				{
					return true;
				}
			}
		}
	}
	return false;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, l, r;
	cin >> n >> l >> r;

	vector<vector<int>> grid(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> grid[i][j];
		}
	}
	int ret = 0;
	while (check(grid, l, r))
	{
		ret++;
		vector<vector<bool>> visit(n, vector<bool>(n, false));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (visit[i][j] == false)
				{
					BorderOpen(grid, i, j, visit, l, r);
				}
			}
		}
	}
	cout << ret;
}