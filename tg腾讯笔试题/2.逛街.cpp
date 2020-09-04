//
// Created by lwl on 2020/7/14.
//

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    vector<int> left;
    vector<int> right;
    stack<int> s1, s2;
    for (int i = 0, j = n - 1; i < n, j >= 0; ++i, --j) {
        left.push_back(s1.size());
        right.push_back(s2.size());
        while (!s1.empty() && v[i] >= s1.top()) s1.pop();
        while (!s2.empty() && v[j] >= s2.top()) s2.pop();
        s1.push(v[i]);
        s2.push(v[j]);
    }
    reverse(right.begin(), right.end());
    for (int k = 0; k < n; ++k) {
        cout << left[k] + right[k] + 1 << " ";
    }
    cout << endl;
}