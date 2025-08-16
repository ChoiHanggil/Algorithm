#include <iostream>
#include <vector>
//#include <map>
//#include <unordered_map>
//#include<string>
//#include<algorithm>
//#include<stack>
#include<queue>
//#include<cmath>
#include <limits>
#include <unordered_set>

using namespace std;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

void BFS(vector<vector<int>> &grid, vector<vector<bool>> &visited, int i, int j, int m)
{
	queue<pair<int, int>> q;
	q.push({ i, j });
	visited[i][j] = true;
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int n = 0; n < 4; n++)
		{
			int nx = x + dx[n];
			int ny = y + dy[n];
			if (nx < 0 || nx >= grid.size() || ny < 0 || ny >= grid.size()) continue;
			if (grid[nx][ny] > m && visited[nx][ny] == false)
			{
				q.push({ nx,ny });
				visited[nx][ny] = true;
			}
		}
	}
}

int main()
{
	int n;
	cin >> n;
	vector<vector<int>> grid(n, vector<int>(n, 0));
	int maxVal = numeric_limits<int>::min();
	unordered_set<int> h;
	h.insert(0);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> grid[i][j];
			maxVal = std::max(grid[i][j], maxVal);
			h.insert(grid[i][j]);
		}
	}
	int ret = 0;
	for (auto m : h)
	{
		int cnt = 0;
		vector<vector<bool>> visited(n, vector<bool>(n, false));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (grid[i][j] > m && visited[i][j] == false)
				{
					cnt++;
					BFS(grid, visited, i, j, m);
				}
			}
		}
		ret = std::max(ret, cnt);
	}

	cout << ret;
}

