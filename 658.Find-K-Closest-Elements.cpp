//
// Created by hqnddw on 2020/5/10.
//
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x) {
        int lo = 0, hi = arr.size();
        vector<int> res;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (arr[mid] > x)
                hi = mid;
            else lo = mid + 1;
        }
        int num = arr[--lo];
        res.push_back(num);
        int l = lo - 1, r = lo + 1;
        while (l >= 0 && r < arr.size() && res.size() < k) {
            if (abs(arr[l] - arr[lo]) <= abs(arr[r]) - arr[lo]) {
                res.push_back(arr[l]);
                l--;
            } else {
                res.push_back(arr[r]);
                r++;
            }
        }
        while (res.size() < k && l >= 0) {
            res.push_back(arr[l]);
            l--;
        }
        while (res.size() < k && r < arr.size()) {
            res.push_back(arr[r]);
            r++;
        }
        sort(res.begin(), res.end());
        return res;
    }
};

int main() {
    vector<int> nums{1, 2, 3, 4, 5};
    Solution s;
    vector<int> res;
    res = s.findClosestElements(nums, 4, 3);
    for (int i : res) {
        cout << i << endl;
    }
}