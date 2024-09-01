//
// Created by 王天柱 on 2024/8/28.
//
#include "P1003.h"
#include <iostream>
#include <vector>

using namespace std;

void P1003() {
    int n;
    cin >> n;
    vector<vector<int>> points;
    for (int i = 0; i < n; i++) {
        int a, b, g, k;
        vector<int> point_iter;
        cin >> a >> b >> g >> k;
        point_iter.push_back(a);
        point_iter.push_back(b);
        point_iter.push_back(g);
        point_iter.push_back(k);
        points.push_back(point_iter);
    }
    int tx, ty;
    cin >> tx >> ty;
    vector<int> carpet;
    for (int i = 1; i <= points.size(); i++) {
        const vector<int>& inner = points.at(i - 1);
        const int a = inner.at(0);
        const int b = inner.at(1);
        const int g = inner.at(2);
        const int k = inner.at(3);
        if (tx >= a && ty >= b && tx <= a + g && ty <= b + k) {
            carpet.push_back(i);
        }
    }
    if (carpet.empty()) {
        cout << -1 << endl;
    } else {
        cout << carpet.at(carpet.size() - 1) << endl;
    }
}