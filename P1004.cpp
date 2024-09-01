//
// Created by 王天柱 on 2024/8/31.
//

#include "P1004.h"
#include <iostream>
using namespace std;

void P1004() {
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n, 0));
    for (;;) {
        int x, y, v;
        cin >> x >> y >> v;
        if (x == 0 && y == 0 && v == 0) {
            break;
        }
        grid[x - 1][y - 1] = v;
    }
}