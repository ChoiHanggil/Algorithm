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

int Distance(pair<int, int> a, vector<vector<bool>> grid)
{
	queue<pair<int,int>> q;
	int d = 0;
	vector<vector<int>> vv(grid.size(), vector<int>(grid[0].size(), 0));
	q.push({ a.first, a.second});
	grid[a.first][a.second] = 0;
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		for (int n = 0; n < 4; n++)
		{
			int nx = x + dx[n];
			int ny = y + dy[n];
			if (nx < 0 || nx >= grid.size() || ny < 0 || ny >= grid[0].size()) continue;
			if (grid[nx][ny] == 1)
			{
				q.push({ nx, ny });
				grid[nx][ny] = 0;
				vv[nx][ny] = vv[x][y] + 1;
			}
		}
	}
	int mx = INT_MIN;
	for (int i = 0; i < vv.size(); i++) {
		for (int j = 0; j < vv[i].size(); j++) {
			mx = max(mx, vv[i][j]);
		}
	}
	return mx;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
	cin >> n >> m;
	
	vector<vector<bool>> grid(n, vector<bool>(m, false));

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < s.size(); j++)
		{
			if (s[j] == 'L')
			{
				grid[i][j] = 1;
			}
		}
	}
	vector<vector<bool>> temp(grid);
	vector<vector<pair<int, int>>> land;



	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (temp[i][j] == 1)
			{
				vector<pair<int, int>> v;
				queue<pair<int, int>> q;
				q.push({ i,j });
				temp[i][j] = 0;
				v.push_back({ i,j });
				while (!q.empty())
				{
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					for (int k = 0; k < 4; k++)
					{
						int nx = x + dx[k];
						int ny = y + dy[k];
						if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
						if (temp[nx][ny] == 1)
						{
							q.push({ nx, ny });
							temp[nx][ny] = 0;
							v.push_back({ nx, ny });
						}
					}
				}
				land.push_back(v);
			}
		}
	}
	
	int ret = -1;

	for (auto& l : land)
	{
		for (int i = 0; i < l.size(); i++)
		{
			ret = max(ret, Distance(l[i], grid));
		}
	}

	cout << ret;

}