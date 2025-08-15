#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    cin >> T;

    while (T--) {
        int n, m, k;
        cin >> n >> m >> k;

        vector<char> grid(n * m, 0);
        int a, b;
        for (int i = 0; i < k; i++) {
            cin >> a >> b;
            grid[a * m + b] = 1;
        }

        int components = 0;
        queue<int> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int code = i * m + j;
                if (grid[code]) {
                    components++;
                    grid[code] = 0;
                    q.push(code);

                    while (!q.empty()) {
                        int cur = q.front(); 
                        q.pop();
                        int x = cur / m, y = cur % m;

                        for (int dir = 0; dir < 4; dir++) {
                            int nx = x + dx[dir], 
                                ny = y + dy[dir];
                            int nxt = nx * m + ny;

                            if (nx < 0 || nx >= n || ny < 0 || ny >= m) 
                                continue;
                            if (grid[nxt]) {
                                grid[nxt] = 0;
                                q.push(nxt);
                            }
                        }
                    }
                }
            }
        }

        cout << components << '\n';
    }

    return 0;
}