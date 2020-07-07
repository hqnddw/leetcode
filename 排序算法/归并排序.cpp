//
// Created by hqnddw on 2020/6/4.
//
#include <vector>
#include <iostream>

using namespace std;

void divide(vector<int> &vector, int i, int n);

void merge(vector<int> &vector, int l, int m, int r);

void merge_sort(vector<int> &nums) {
    divide(nums, 0, nums.size() - 1);
}

void divide(vector<int> &nums, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        divide(nums, l, m);
        divide(nums, m + 1, r);
        merge(nums, l, m, r);
    }
}

void merge(vector<int> &nums, int l, int m, int r) {
    vector<int> v1(m - l + 1);
    vector<int> v2(r - m);
    for (int i = 0; i < v1.size(); ++i) {
        v1[i] = nums[l + i];
    }
    for (int j = 0; j < v2.size(); ++j) {
        v2[j] = nums[m + 1 + j];
    }

    int i = 0, j = 0, k = l;
    while (i < v1.size() && j < v2.size()) {
        if (v1[i] < v2[j]) {
            nums[k] = v1[i];
            i++;
        } else {
            nums[k] = v2[j];
            j++;
        }
        k++;
    }
    while (i < v1.size()) {
        nums[k] = v1[i];
        i++;
        k++;
    }
    while (j < v2.size()) {
        nums[k] = v2[j];
        j++;
        k++;
    }
}

int main() {
    vector<int> v{6, 8, 1, 7, 11, 55, 98, 23, 12, 10, 4, 99, 3};
    merge_sort(v);
    for (int i : v) {
        cout << i << " ";
    }
    cout << endl;
}