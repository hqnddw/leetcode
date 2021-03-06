//
// Created by hqnddw on 2019/10/29.
//
#include <vector>
#include <unordered_map>

using namespace std;


class Solution1 {
public:
    void sortColors(vector<int> &nums) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); ++i) {
            if (map.count(nums[i]))
                map[nums[i]] += 1;
            else map[nums[i]] = 1;
        }
        int p = 0;
        for (int i = 0; i < 2; ++i) {
            int j = map[i];
            while (j--) {
                nums[p] = i;
                p++;
            }
        }
    }
};


class Solution2 {
public:
    void sortColors(vector<int> &nums) {
        int p1 = 0;
        int p2 = nums.size() - 1;
        for (int i = 0; i <= p2; i++) {
            while (nums[i] == 2 && i < p2)
                swap(nums[i], nums[p2--]);
            while (nums[i] == 0 && i > p1)
                swap(nums[i], nums[p1++]);
        }
    }
};


class Solution3 {
public:
    void sortColors(vector<int> &nums) {
        unordered_map<int, int> map;
        for (int i : nums) {
            if (map.count(i))
                map[i] += 1;
            else map[i] = 1;
        }
        for (int k = 0, j = 0; k < 3; ++k) {
            while (map[k]--) {
                nums[j] = k;
                j++;
            }
        }
    }
};


class Solution4 {
public:
    void sortColors(vector<int> &nums) {
        int lo = 0;
        int hi = nums.size() - 1;
        for (int i = 0; i <= hi; ++i) {
            while (nums[i] == 2 && i < hi) {
                swap(nums[i], nums[hi--]);
            }
            while (nums[i] == 0 && i > lo) {
                swap(nums[i], nums[lo++]);
            }
        }
    }
};