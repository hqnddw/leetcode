//
// Created by lwl on 2020/7/4.
//

#include <vector>
#include <iostream>

using namespace std;
//为什么返回 left 而不是 right？
//答：都是一样的，因为 while 终止的条件是 left == right。
int left_bound1(vector<int> nums, int target) {
    if (nums.size() == 0) return -1;
    int left = 0;
    int right = nums.size(); // 注意

    while (left < right) { // 注意
        int mid = (left + right) / 2;
        if (nums[mid] == target) {
            right = mid;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid; // 注意
        }
    }
    if (left == nums.size()) return -1;
    return nums[left] == target ? left : -1;;
}

//能不能想办法把 right 变成 nums.length - 1，也就是继续使用两边都闭的「搜索区间」？
// 这样就可以和第一种二分搜索在某种程度上统一起来了。
int left_bound2(vector<int> nums, int target) {
    int left = 0, right = nums.size() - 1;
    // 搜索区间为 [left, right]
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) {
            // 搜索区间变为 [mid+1, right]
            left = mid + 1;
        } else if (nums[mid] > target) {
            // 搜索区间变为 [left, mid-1]
            right = mid - 1;
        } else if (nums[mid] == target) {
            // 收缩右侧边界
            right = mid - 1;
        }
    }
    //由于 while 的退出条件是 left == right + 1，
    //所以当 target 比 nums 中所有元素都大时，会存在以下情况使得索引越界
    // 检查出界情况
    if (left >= nums.size() || nums[left] != target)
        return -1;
    return left;
}







int main() {
    vector<int> v{1, 2, 2, 2, 3};
    cout << left_bound1(v, 2) << endl;
}