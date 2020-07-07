//
// Created by hqnddw on 2020/6/4.
//
#include <vector>
#include <iostream>

using namespace std;

//初始
void bubble_sort(vector<int> &nums) {
    for (int i = 0; i < nums.size(); ++i) {
        for (int j = 1; j < nums.size() - i; ++j) {
            if (nums[j - 1] > nums[j])
                swap(nums[j - 1], nums[j]);
        }
    }
}

//优化，提前结束
void bubble_sort1(vector<int> &nums) {
    for (int i = 0; i < nums.size(); ++i) {
        int flag = 1;
        for (int j = 1; j < nums.size() - i; ++j) {
            if (nums[j - 1] > nums[j]) {
                swap(nums[j - 1], nums[j]);
                flag = 0;
            }
        }
        if (flag) break;
    }
}

int main() {
    vector<int> v{6, 8, 1, 7, 11, 55, 98, 23, 12, 10, 4, 99};
    bubble_sort1(v);
    for (int i : v) {
        cout << i << " ";
    }
    cout << endl;
}