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


class Solution {
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