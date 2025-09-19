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

//int dx[4] = { -1, 0, 1, 0 };
//int dy[4] = { 0, 1, 0, -1 };

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> v(3, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	int atk[6][3] = {
	{9,3,1}, {9,1,3}, {3,9,1}, {3,1,9}, {1,9,3}, {1,3,9}
	};

	queue<pair<int, vector<int>>> q;
	q.push({ 0,v });
	bool visited[61][61][61] = { false };
	visited[v[0]][v[1]][v[2]] = true;
	while (!q.empty())
	{
		vector<int> temp = q.front().second;
		int cnt = q.front().first;
		q.pop();
		if (temp[0] == 0 && temp[1] == 0 && temp[2] == 0)
		{
			cout << cnt << "\n";
			return 0;
		}
		for (int i = 0; i < 6; i++)
		{
			int na = max(0, temp[0] - atk[i][0]);
			int nb = max(0, temp[1] - atk[i][1]);
			int nc = max(0, temp[2] - atk[i][2]);

			if (!visited[na][nb][nc])
			{
				visited[na][nb][nc] = true;
				q.push({ cnt + 1, {na, nb, nc} });
			}
		}
	}
	

}