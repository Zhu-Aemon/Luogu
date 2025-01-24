//
// Created by wtz on 1/23/25.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int compare(int a, int b, int c, int d) {
    int m1 = max(a, b);
    int m2 = max(c, d);
    return max(m1, m2);
}

int main() {
    int m = 0;
    int n = 0;
    cin >> m >> n;
    vector matrix(m, vector<int>(n));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    /* 可以理解为两个棋子同时从左上往右下走并且不能重合
     * 一共是三个维度：步数s，第一个棋子的坐标x1，第二个棋子的坐标x2
     * dp是一个三维数组，s/x1/x2
     *
     * 注意点：需要处理循环的范围，防止越界
     */
    int s = n + m - 2;
    int dp[101][51][51] = {0};
    for (int step = 1; step <= s; step++) {
        for (size_t x1 = max(0, step - m + 1); x1 <= min(step, n - 1); x1++) {
            for (size_t x2 = max(0, step - m + 1); x2 <= min(step, n - 1); x2++) {
                const bool p1_dest = x1 == n - 1 && step - x1 == m - 1;
                const bool p2_dest = x2 == n - 1 && step - x2 == m - 1;

                if (x1 == x2 && !p1_dest && !p2_dest ) {
                    continue;
                }

                if (x1 == 0 and x2 != 0) {
                    dp[step][x1][x2] = max(
                    dp[step - 1][x1][x2],
                    dp[step - 1][x1][x2 - 1]
                    ) + matrix[x1][step - x1] + matrix[x2][step - x2];
                } else if (x2 == 0 and x1 != 0) {
                    dp[step][x1][x2] = max(
                    dp[step - 1][x1][x2],
                    dp[step - 1][x1 - 1][x2]
                    ) + matrix[x1][step - x1] + matrix[x2][step - x2];
                } else {
                    dp[step][x1][x2] = compare(
                    dp[step - 1][x1][x2],
                    dp[step - 1][x1 - 1][x2],
                    dp[step - 1][x1][x2 - 1],
                    dp[step - 1][x1 - 1][x2 - 1]
                    ) + matrix[x1][step - x1] + matrix[x2][step - x2];
                }
            }
        }
    }

    cout << dp[s][m - 1][n - 1];
    return 0;
}