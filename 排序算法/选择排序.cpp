//
// Created by hqnddw on 2020/6/4.
//
#include <vector>
#include <iostream>

using namespace std;

void select_sort(vector<int> &nums) {
    for (int i = 0; i < nums.size(); ++i) {
        int min_index = i;
        for (int j = i + 1; j < nums.size(); ++j) {
            if (nums[j] < nums[min_index])
                min_index = j;
        }
        swap(nums[min_index], nums[i]);
    }
}

int main() {
    vector<int> v{6, 8, 1, 7, 11, 55, 98, 23, 12, 10, 4, 99};
    select_sort(v);
    for (int i : v) {
        cout << i << " ";
    }
    cout << endl;
}