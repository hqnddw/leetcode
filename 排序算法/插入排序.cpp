//
// Created by hqnddw on 2020/6/4.
//
#include <vector>
#include <iostream>

using namespace std;

void insert_sort(vector<int> &nums) {
    for (int i = 1; i < nums.size(); ++i) {
        int tmp = nums[i];
        int j = i - 1;
        while (j >= 0 && nums[j] > tmp) {
            nums[j + 1] = nums[j];
            j--;
        }
        nums[j + 1] = tmp;
    }
}

int main() {
    vector<int> v{6, 8, 1, 7, 11, 55, 98, 23, 12, 10, 4, 99};
    insert_sort(v);
    for (int i : v) {
        cout << i << " ";
    }
    cout << endl;
}