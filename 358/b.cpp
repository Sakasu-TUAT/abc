#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

struct State {
    int x, y;
    long long fun;
    int steps;
};

int main() {
    int h, w, si, sj;
    long long k;
    cin >> h >> w >> k >> si >> sj;

    // グリッドの楽しさを格納
    vector<vector<long long>> a(h, vector<long long>(w));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> a[i][j];
        }
    }

    // 初期位置を0-indexedに変換
    si--; sj--;

    // BFSで最短距離を計算
    vector<vector<int>> dist(h, vector<int>(w, INT_MAX));
    dist[si][sj] = 0;

    queue<pair<int, int>> q;
    q.push({si, sj});
    vector<int> dx = {0, 1, 0, -1};
    vector<int> dy = {1, 0, -1, 0};

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int dir = 0; dir < 4; ++dir) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx >= 0 && nx < h && ny >= 0 && ny < w && dist[nx][ny] == INT_MAX) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    // DP配列を初期化
    vector<vector<long long>> dp(h, vector<long long>(w, LLONG_MIN));
    dp[si][sj] = a[si][sj];

    // BFSを利用してDPで楽しさの最大値を計算
    q.push({si, sj});
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int dir = 0; dir < 4; ++dir) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx >= 0 && nx < h && ny >= 0 && ny < w) {
                if (dist[nx][ny] == dist[x][y] + 1) {
                    long long new_fun = dp[x][y] + a[nx][ny];
                    if (new_fun > dp[nx][ny]) {
                        dp[nx][ny] = new_fun;
                        q.push({nx, ny});
                    }
                }
            }
        }
    }

    // 各マスへの最大の楽しさを格納
    vector<vector<long long>> max_fun_from_start(h, vector<long long>(w));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            max_fun_from_start[i][j] = dp[i][j];
        }
    }

    // Kが非常に大きい場合
    if (k > h * w) {
        // グリッド全体での最大楽しさの計算
        long long max_fun = LLONG_MIN;
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                max_fun = max(max_fun, max_fun_from_start[i][j]);
            }
        }

        // 最大楽しさのマスを見つける
        long long result = max_fun + (k - h * w) * max_fun;

        cout << result << endl;
    } else {
        // Kが小さい場合の楽しさの最大値を計算
        long long result = 0;
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                result = max(result, max_fun_from_start[i][j]);
            }
        }

        cout << result << endl;
    }

    return 0;
}
