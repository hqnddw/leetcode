//
// Created by lwl on 2020/7/14.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//间隔合并，排序，贪心，dp
int main() {
    int n, L;
    cin >> n >> L;
    vector<vector<int>> res;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        res.push_back({a, b});
    }
    sort(res.begin(), res.end());
    int count = 0;
    for (int i = 0, start = 0, end = 0; start < L; start = end, count++) {
        while (i < n && res[i][0] <= start) {
            end = max(end, res[i][1]);
            i++;
        }
        if (start == end) {
            count = -1;
            break;
        };
    }
    cout << count << endl;
    return 0;
}