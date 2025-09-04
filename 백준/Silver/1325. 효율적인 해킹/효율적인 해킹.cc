
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


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
	cin >> n >> m;
	int a, b;
	vector<vector<int>> adj(n + 1);
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		adj[b].push_back(a);
	}

	vector<int> hackCnt(n + 1, 0);
	vector<int> visited(n + 1, 0);

	int visit_id = 0;
	int maxCnt = 0;

	for (int i = 1; i <= n; i++)
	{
		visit_id++;
		int cnt = 0;
		
		queue<int> q;
		q.push(i);
		visited[i] = visit_id;
		while (!q.empty())
		{

			int front = q.front();
			q.pop();
			for (auto e : adj[front])
			{
				if (visited[e] != visit_id)
				{
					visited[e] = visit_id;
					q.push(e);
					cnt++;
				}
			}
		}

		hackCnt[i] = cnt;
		if (cnt > maxCnt) maxCnt = cnt;
	}

	for (int i = 1; i <= n; i++)
	{
		if (hackCnt[i] == maxCnt)
		{
			cout << i << " ";
		}
	}
}


