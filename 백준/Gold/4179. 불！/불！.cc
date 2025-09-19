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

	
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> grid(n, vector<int>(m, 0));
	int jx, jy, fx, fy;
	queue<pair<int, int>> fq;
	vector<vector<int>> temp(grid);
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < s.size(); j++)
		{
			switch (s[j])
			{
			case '#':
				grid[i][j] = INT_MIN;
				break;
			case 'J':
				grid[i][j] = 1;
				jx = i; jy = j;
				break;
			case 'F':
				temp[i][j] = -1;
				fq.push({ i,j });
				break;
			}
		}
	}


	while (!fq.empty())
	{
		int x = fq.front().first;
		int y = fq.front().second;
		fq.pop();
		for (int d = 0; d < 4; d++)
		{
			int nx = x + dx[d];
			int ny = y + dy[d];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (grid[nx][ny] == 0 && temp[nx][ny] == 0)
			{
				fq.push({ nx,ny });
				temp[nx][ny] = temp[x][y] - 1;
			}
		}
	}

	if (jx == 0 || jx == n - 1 || jy == 0 || jy == m - 1) {
		cout << 1 << "\n";
		return 0;
	}
	queue<pair<int, int>> q;
	vector<vector<bool>> visit(n, vector<bool>(m, 0));
	q.push({ jx,jy });
	visit[jx][jy] = 1;
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int d = 0; d < 4; d++)
		{
			int nx = x + dx[d];
			int ny = y + dy[d];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (visit[nx][ny] == 0 && grid[nx][ny] == 0)
			{
				if (grid[x][y] + 1 < abs(temp[nx][ny]) || temp[nx][ny] == 0)
				{
					if (nx == 0 || nx == n - 1 || ny == 0 || ny == m - 1)
					{
						cout << grid[x][y] + 1 << "\n";
						return 0;
					}
					visit[nx][ny] = 1;
					grid[nx][ny] = grid[x][y] + 1;
					q.push({ nx,ny });
				}
			}
		}
	}

	cout << "IMPOSSIBLE\n";
}