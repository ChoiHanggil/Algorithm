#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include<string>
#include<algorithm>
#include<stack>
#include<queue>
#include<cmath>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    string s;
    vector<vector<int>> grid(n);

    for (int i = 0; i < n; i++)
    {
        cin >> s;
        for (auto c : s)
        {
            grid[i].push_back(c-48);
        }
    }
    vector<vector<int>> visit(n, vector<int>(m , 0));

    queue<pair<int, int>> q;
    q.push({ 0, 0 });
    visit[0][0] = 1;
    while (q.size())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        int dx[4] = { -1, 0, 1, 0 };
        int dy[4] = { 0, -1, 0, 1 };
       
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (grid[nx][ny] == 1 && visit[nx][ny] == 0)
            {
                q.push({ nx, ny });
                visit[nx][ny] = visit[x][y] + 1;
            }
        }
    }

    cout << visit[n-1][m-1];
}

