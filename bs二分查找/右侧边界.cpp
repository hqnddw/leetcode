//
// Created by lwl on 2020/7/4.
//

#include <vector>
#include <iostream>

using namespace std;
// 为什么最后返回 left - 1 而不像左侧边界的函数，返回 left？
// 而且我觉得这里既然是搜索右侧边界，应该返回 right 才对。
// 答：首先，while 循环的终止条件是 left == right，所以 left 和 right 是一样的，
// 你非要体现右侧的特点，返回 right - 1 好了。至于为什么要减一
// 因为我们对 left 的更新必须是 left = mid + 1，就是说 while 循环结束时，
// nums[left] 一定不等于 target 了，而 nums[left-1] 可能是 target。
int right_bound1(vector<int> nums, int target) {
    if (nums.size() == 0) return -1;
    int left = 0, right = nums.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target)
            left = mid + 1; // 注意
        else if (nums[mid] < target)
            left = mid + 1;
        else right = mid;
    }
    if (left == 0) return -1;
    return nums[left-1] == target ? (left-1) : -1;
}

int right_bound2(vector<int> nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid - 1;
        } else if (nums[mid] == target) {
            // 这里改成收缩左侧边界即可
            left = mid + 1;
        }
    }
    // 这里改为检查 right 越界的情况，见下图
    if (right < 0 || nums[right] != target)
        return -1;
    return right;
}