//
// Created by lwl on 2020/7/4.
//
#include <vector>

using namespace std;

int binarySearch_1(vector<int> &nums, int target) {
    int l = 0, r = nums.size() - 1;
    //while(left <= right) 的终止条件是 left == right + 1，
    //写成区间的形式就是 [right + 1, right],可见这时候区间为空
    //所以这时候 while 循环终止是正确的，直接返回 -1 即可。
    while (l <= r) {
        int mid = (l + r) / 2;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] > target)
            r = mid - 1;
        else l = mid + 1;
    }
    return -1;
}

int binarySearch_2(vector<int> &nums, int target) {
    int left = 0, right = nums.size() - 1;
    //while(left < right) 的终止条件是 left == right，写成区间的形式就是 [left, right]，
    //或者带个具体的数字进去 [2, 2]，这时候区间非空，还有一个数 2，但此时 while 循环终止了。
    //也就是说这区间 [2, 2] 被漏掉了，索引 2 没有被搜索，如果这时候直接返回 -1 就是错误的。
    //我们可以在返回处打一个补丁：return nums[left] == target ? left : -1;
    while (left < right) {
        int mid = (left + right) / 2;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] > target)
            right = mid - 1;
        else left = mid + 1;
    }
    return nums[left] == target ? left : -1;
}