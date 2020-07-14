//
// Created by yida on 2020/5/20.
//
#include <vector>
#include <stack>

using namespace std;

//dp动态规划
class Solution1 {
public:
    int largestRectangleArea(vector<int> &heights) {
        if (heights.empty())
            return 0;
        vector<int> minLeft(heights.size(), -1);
        for (int i = 1; i < heights.size(); ++i) {
            int p = i - 1;
            while (p >= 0 && heights[p] >= heights[i])
                p = minLeft[p];
            minLeft[i] = p;
        }
        vector<int> minRight(heights.size(), heights.size());
        for (int j = heights.size() - 2; j >= 0; --j) {
            int p = j + 1;
            while (p < heights.size() && heights[p] >= heights[j])
                p = minRight[p];
            minRight[j] = p;
        }
        int res = 0;
        for (int k = 0; k < heights.size(); ++k) {
            res = max(res, (minRight[k] - minLeft[k] - 1) * heights[k]);
        }
        return res;
    }
};


//栈
class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        height.push_back(0);
        int n = height.size(), area = 0;
        stack<int> indexes;
        for (int i = 0; i < n; i++) {
            while (!indexes.empty() && height[indexes.top()] > height[i]) {
                int h = height[indexes.top()]; indexes.pop();
                int l = indexes.empty() ? -1 : indexes.top();
                area = max(area, h * (i - l - 1));
            }
            indexes.push(i);
        }
        return area;
    }
};