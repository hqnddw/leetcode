//
// Created by hqnddw on 2019/9/6.
//
#include <vector>

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


class Solution {
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