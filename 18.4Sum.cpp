//
// Created by hqnddw on 2019/9/7.
//
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution1 {
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> v;
        for (int i = 0; i < n - 3; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            if ((nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3]) > target) break;
            if ((nums[i] + nums[n - 3] + nums[n - 2] + nums[n - 1]) < target) continue;
            for (int j = i + 1; j < n - 2; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                if ((nums[i] + nums[j] + nums[j + 1] + nums[j + 2]) > target) break;
                if ((nums[i] + nums[j] + nums[n - 2] + nums[n - 1] < target)) continue;
                int lo = j + 1;
                int hi = n - 1;
                while (lo < hi) {
                    int sum = nums[i] + nums[j] + nums[lo] + nums[hi];
                    if (sum < target) lo++;
                    else if (sum > target) hi--;
                    else {
                        v.push_back({nums[i], nums[j], nums[lo], nums[hi]});
                        while (lo < hi && nums[lo] == nums[lo + 1]) lo++;
                        while (lo < hi && nums[hi] == nums[hi - 1]) hi--;
                        lo++, hi--;
                    }
                }

            }
        }
        return v;
    }
};

//int main() {
//    Solution s;
//    vector<vector<int>> v;
//    vector<int> nums{0, 0, 0, 0};
//    int target = 0;
//    v = s.fourSum(nums, target);
//    for (auto i:v) {
//        cout << "[";
//        for (auto j :i)
//            cout << j << ", ";
//        cout << "]" << endl;
//    }
//}

class Solution2 {
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> v;
        int cursum = 0;
        int n = nums.size();
        for (int i = 0; i < n - 3; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) break;
            if (nums[i] + nums[n - 1] + nums[n - 2] + nums[n - 3] < target) continue;
            for (int j = i + 1; j < n - 2; ++j) {
                if (j > i + 1 && nums[j] == nums[j + 1]) continue;
                if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) break;
                if (nums[i] + nums[j] + nums[n - 1] + nums[n - 2] < target) continue;
                int lo = j + 1;
                int hi = n - 1;
                while (lo < hi) {
                    cursum = nums[i] + nums[j] + nums[lo] + nums[hi];
                    if (cursum == target) {
                        v.push_back({nums[i], nums[j], nums[lo], nums[hi]});
                        while (lo < hi && nums[lo] == nums[lo + 1]) lo++;
                        while (lo < hi && nums[hi] == nums[hi - 1]) hi--;
                        lo++, hi--;
                    } else if (cursum > target) hi--;
                    else lo++;
                }
            }
        }
        return v;
    }
};


class Solution3 {
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> v;
        for (int i = 0; i < n - 3; ++i) {
            if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) break;
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            if (nums[i] + nums[n - 1] + nums[n - 2] + nums[n - 3] < target) continue;
            for (int j = i + 1; j < n - 2; ++j) {
                if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) break;
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                if (nums[i] + nums[j] + nums[n - 1] + nums[n - 2] < target) continue;
                int lo = j + 1;
                int hi = n - 1;
                while (lo < hi) {
                    int sum = nums[i] + nums[j] + nums[lo] + nums[hi];
                    if (sum == target) {
                        v.push_back({nums[i], nums[j], nums[lo], nums[hi]});
                        while (lo < hi && nums[hi] == nums[hi - 1]) hi--;
                        while (lo < hi && nums[lo] == nums[lo + 1]) lo++;
                        lo++, hi--;
                    } else if (sum > target) hi--;
                    else lo++;
                }
            }
        }
        return v;
    }
};