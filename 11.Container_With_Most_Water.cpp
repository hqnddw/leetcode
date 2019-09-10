//
// Created by hqnddw on 2019/9/6.
//
#include <vector>
#include <iostream>

using namespace std;

class Solution1 {
public:
    int maxArea(vector<int> &height) {
        int i = 0;
        int j = height.size() - 1;
        int maximum = min(height[0], height[height.size() - 1]) * (height.size() - 1);
        while (i < j - 1) {
            if (height[i] < height[j]) {
                i++;
                if (height[i] < height[j])
                    maximum = max(height[i] * (j - i), maximum);
                else maximum = max(height[j] * (j - i), maximum);
            } else {
                j--;
                if (height[i] < height[j])
                    maximum = max(height[i] * (j - i), maximum);
                else maximum = max(height[j] * (j - i), maximum);
            }
        }
        return maximum;
    }
};


class Solution2 {
public:
    int maxArea(vector<int> &height) {
        int i = 0;
        int j = height.size() - 1;
        int re = 0;
        while (i < j) {
            re = max(re, min(height[i], height[j]) * (j - i));
            height[i] < height[j] ? i++ : j--;
        }
        return re;
    }
};


class Solution {
public:
    int maxArea(vector<int> &height) {
        int i = 0;
        int j = height.size() - 1;
        int maxvalue = 0;
        while (i <= j) {
            maxvalue = max(maxvalue, min(height[i], height[j]) * (j - i));
            if (height[i] < height[j])
                i++;
            else j--;
        }
        return maxvalue;
    }
};

//int main() {
//    Solution s;
//    vector<int> nums{1, 8, 6, 2, 5, 4, 8, 3, 7};
//    cout << s.maxArea(nums) << endl;
//}