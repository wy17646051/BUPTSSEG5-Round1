#include <iostream>


int mmap[n + 1][n + 1];
int visited[n + 1][n + 1];

//DFS
bool connected(int i, int j) {
    if (!visited[i][j] && i <= n && j <= n) {
        if (mmap[i][j] == 1)
            return true;
        visited[i][j] = 1;
        connected(...);
    }
}


int main() {
    int n, m, s;
    cin >> n >> m >> s;
    // 有向图
    // 0 denotes unreachable
    // 1 denotes reachable
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            mmap[i][j] = 0;
            visited = 0;
        }
        map[i][i] = 1;
    }

    // input roads
    int row, col;
    for (int k = 0; k < m; ++k) {
        cin >> row >> col;
        mmap[row][col] = 1;

    }

    int ans = 0;

    // 测试，从s出发,DFS
    for (int i = 1; i <= n; ++i) {
        if (connected(s, i)) {
            continue;
        } else {
            ans++;
            mmap[s][i] = 1;
        }
    }

    cout << ans << endl;
    return 0;
}