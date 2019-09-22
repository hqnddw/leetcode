//
// Created by hqnddw on 2019/9/6.
//

#include <vector>
#include <algorithm>

using namespace std;

class Solution1 {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> re;
        if (nums.size() < 3)
            return re;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; ++i) {
            if (i == 0 || (i > 0 && nums[i] != nums[i - 1])) {
                int lo = i + 1;
                int hi = nums.size() - 1;
                int sum = 0 - nums[i];
                while (lo < hi) {
                    if (nums[lo] + nums[hi] == sum) {
                        re.push_back({nums[i], nums[lo], nums[hi]});
                        while (lo < hi && nums[lo] == nums[lo + 1]) lo++;
                        while (lo < hi && nums[hi] == nums[hi - 1]) hi--;
                        lo++;
                        hi--;
                    } else if (nums[lo] + nums[hi] < sum)
                        lo++;
                    else hi--;
                }
            }
        }
        return re;
    }
};


class Solution2 {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> v;
        if (nums.size() < 3)
            return v;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; ++i) {
            if (i == 0 || (i > 0 && nums[i] != nums[i - 1])) {
                int lo = i + 1;
                int hi = nums.size() - 1;
                int cursum = nums[i] + nums[lo] + nums[hi];
                while (lo < hi) {
                    if (cursum == 0) {
                        v.push_back({nums[i], nums[lo], nums[hi]});
                        while (lo < hi && nums[lo] == nums[lo + 1]) lo++;
                        while (lo < hi && nums[hi] == nums[hi - 1]) hi--;
                        lo++, hi--;
                    } else if (cursum > 0) hi--;
                    else lo++;
                }
            }
        }
        return v;
    }
};


class Solution3 {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> v;
        if (nums.size() < 3) return v;
        for (int i = 0; i < nums.size() - 2; ++i) {
            if (i == 0 || (i > 0 && nums[i] != nums[i - 1])) {
                int lo = i + 1;
                int hi = nums.size() - 1;
                while (lo < hi) {
                    int sum = nums[i] + nums[lo] + nums[hi];
                    if (sum == 0) {
                        v.push_back({nums[i], nums[lo], nums[hi]});
                        while (lo < hi && nums[lo] == nums[lo + 1]) lo++;
                        while (lo < hi && nums[hi] == nums[hi - 1]) hi--;
                        lo++, hi--;
                    } else if (sum > 0) hi--;
                    else lo++;
                }
            }
        }
        return v;
    }
};


class Solution4 {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        if (nums.empty())
            return res;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (i == 0 || (i > 0 && nums[i] != nums[i - 1])) {
                int lo = i + 1;
                int hi = n - 1;
                while (lo < hi) {
                    int curSum = nums[i] + nums[lo] + nums[hi];
                    if (curSum == 0) {
                        res.push_back({nums[i], nums[lo], nums[hi]});
                        while (lo < hi && nums[lo] == nums[lo + 1]) lo++;
                        while (lo < hi && nums[hi] == nums[hi - 1]) hi--;
                        lo++, hi--;
                    } else if (curSum > 0) hi--;
                    else lo++;
                }
            }
        }
        return res;
    }
};