//
// Created by hqnddw on 2020/9/14.
//
#include <iostream>
#include <vector>

using namespace std;

int get_min(vector<int> &nums) {
    int res = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
        res = min(res, nums[i]);
    }
    return res;
}

int get_max(vector<int> &nums) {
    int res = nums[1];
    for (int i = 1; i < nums.size(); ++i) {
        res = max(res, nums[i]);
    }
    return res;
}

void count_sort(vector<int> &nums) {
    int min = get_min(nums);
    int max = get_max(nums);
    vector<int> count(max - min + 1);
    for (int i : nums)
        count[i - min]++;
    for (int j = 1; j < count.size(); ++j) {
        count[j] += count[j - 1];
    }
    vector<int> tmp(nums.size(), 0);
    for (int k = nums.size()-1; k >= 0; --k) {
        tmp[count[nums[k] - min] - 1] = nums[k];
        count[nums[k] - min]--;
    }
    nums = tmp;
}

void Print(vector<int> &nums) {
    for (int i :nums)
        cout << i << " ";
    cout << endl;
}

int main() {
    vector<int> nums{47, 65, 20, 66, 25, 53, 64, 69, 72, 22,
                     74, 25, 53, 15, 42, 36, 4, 69, 86, 19};

    cout << "Original Array = ";
    Print(nums);
    count_sort(nums);
    cout << "Sorted Array = ";
    Print(nums);

    return 0;
}