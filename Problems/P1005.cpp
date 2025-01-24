#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

// 实现对__int128的运算符重载
istream& operator>>(istream& in, __int128& num) {
    string s;
    in >> s;
    num = 0;
    bool neg = s[0] == '-';
    for (size_t i = neg? 1: 0; i < s.size(); i++) {
        num = 10 * num + (s[i] - '0');
    }
    if (neg) num = -num;
    return in;
}

ostream& operator<<(ostream& out, __int128& num) {
    if (num == 0) {
        out << '0';
        return out;
    }
    __int128 n = num;
    if (n < 0) {
        out << '-';
        n = -n;
    }
    string s;
    while (n > 0) {
        s += '0' + n % 10;
        n /= 10;
    }
    reverse(s.begin(), s.end());
    out << s;
    return out;
}

// 高精度pow计算
__int128 hp_pow(const int x, int y) {
    __int128 result = x;
    while (y > 1) {
        result *= x;
        y--;
    }
    return result;
}

// 使用迭代方式计算区间 DP
__int128 line(const __int128* d, const int n) {
    __int128 dp[80][80];

    // 开始循环
    for (int len = 1; len <= n; len++) {  // 这是区间的长度
        for (int i = 0; i <= n - len; i++) {  // 这是区间的左端点
            int j = i + len - 1;  // 这是区间的右端点
            if (i == j) { // 处理区间长度为1的情况
                dp[i][j] = d[i] * hp_pow(2, n - len + 1);
            } else {
                dp[i][j] = max(dp[i + 1][j] + hp_pow(2, n - len + 1) * d[i], dp[i][j - 1] + hp_pow(2, n - len + 1) * d[j]);
            }
        }
    }

    return dp[0][n - 1];
}

int main() {
    int n = 0;
    int m = 0;
    cin >> n >> m;
    vector inputs(n, vector<__int128>(m));
    for (int i = 0; i < n; i++) {
        for (int j =0; j < m; j++) {
            cin >> inputs[i][j];
        }
    }

    __int128 result = 0;
    for (int i = 0; i < n; i++) {
        const __int128 res_row = line(inputs[i].data(), m);
        result += res_row;
    }

    cout << result;
}
