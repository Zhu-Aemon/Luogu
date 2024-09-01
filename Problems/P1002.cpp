//
// Created by 王天柱 on 2024/8/28.
//
#include "P1002.h"
#include <iostream>
#include <map>

using namespace std;

map<pair<int, int>, long long> buffer;

auto get_path(int x, int y) -> long long {
    if ((x < 0) || (y < 0)) {
        return 0;
    }
    if (const auto path = buffer.find({x, y}); path != buffer.end()) {
        return path->second;
    }
    const long long total_paths = get_path(x - 1, y) + get_path(x, y - 1);
    buffer[{x, y}] = total_paths;
    return total_paths;
}

void P1002() {
    int bx, by, hx, hy;
    cin >> bx >> by >> hx >> hy;

    // calculate control points
    int controls[9][2] = {
        {hx - 1, hy - 2}, {hx - 2, hy - 1}, {hx - 1, hy + 2}, {hx - 2, hy + 1}, {hx + 1, hy - 2},
        {hx + 2, hy - 1}, {hx + 1, hy + 2}, {hx + 2, hy + 1}, {hx, hy}
    };
    for (const auto & control : controls) {
        int x_iter = control[0];
        int y_iter = control[1];
        buffer[{x_iter, y_iter}] = 0;
    }
    buffer[{0, 0}] = 1;
    const long long total_B_paths = get_path(bx, by);
    cout << total_B_paths << endl;

    // for (const auto & item: buffer) {
    //     if (item.second < 0) {
    //         cout << item.first.first << ", " << item.first.second << ", " << item.second << endl;
    //     }
    // }
    // cout << get_path(17, 19);
}
