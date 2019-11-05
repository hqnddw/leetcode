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