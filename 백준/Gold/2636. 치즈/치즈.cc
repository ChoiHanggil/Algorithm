
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

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void AirSearch(vector<vector<int>> &grid, int i, int j)
{
	queue<pair<int, int>> q;
	q.push({ i,j });
	grid[i][j] = -1;
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int d = 0; d < 4; d++)
		{
			int nx = x + dx[d];
			int ny = y + dy[d];
			if (nx < 0 || nx >= grid.size() || ny < 0 || ny >= grid[0].size()) continue;
			if (grid[nx][ny] == 0)
			{
				q.push({ nx,ny });
				grid[nx][ny] = -1;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> grid(n);
	int a;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a;
			grid[i].push_back(a);
		}
	}
	
	AirSearch(grid, 0, 0);

	int time = 0;
	int prevCnt = 0;

	while (true)
	{
		vector<pair<int, int>> melt;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (grid[i][j] == 1)
				{
					for (int d = 0; d < 4; d++)
					{
						int nx = i + dx[d];
						int ny = j + dy[d];
						if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
						if (grid[nx][ny] == -1)
						{
							melt.push_back({ i,j });
							break;
						}
					}
				}
			}
		}
		if (melt.empty()) break;

		prevCnt = melt.size();
		for (auto &e : melt)
		{
			for (int d = 0; d < 4; d++)
			{
				int nx = e.first + dx[d];
				int ny = e.second + dy[d];
				if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
				if (grid[nx][ny] == 0)
				{
					AirSearch(grid, nx, ny);
				}
			}
			grid[e.first][e.second] = -1;
		}

		time++;
	}

	cout << time << '\n';
	cout << prevCnt << '\n';
}


