#include <iostream>
#include <vector>
#include <cstdint>

const int MOD = 998244353;

// べき乗を計算する関数（繰り返し二乗法を使用）
int64_t power(int64_t base, int64_t exponent) {
    int64_t result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        exponent /= 2;
    }
    return result;
}

int main() {
    int N;
    int64_t X;
    std::cin >> N >> X;

    // 曲の長さを取得
    std::vector<int64_t> T(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> T[i];
    }

    // 総再生時間を計算
    int64_t total_duration = 0;
    for (int i = 0; i < N; ++i) {
        total_duration += T[i];
    }

    // 曲1が再生される確率を計算
    int64_t probability = 0;
    for (int i = 0; i < N; ++i) {
        int64_t duration = X - total_duration;
        if (duration >= 0 && duration % T[i] == 0) {
            int64_t ways = power(2, duration / T[i]);
            probability = (probability + ways) % MOD;
        }
    }

    std::cout << probability << std::endl;

    return 0;
}
