//
// Created by hqnddw on 2019/9/24.
//
#include <vector>
#include <stack>

using namespace std;

//双指针
class Solution1 {
public:
    int trap(vector<int> &height) {
        int left = 0;
        int right = height.size() - 1;
        int max_left = 0;
        int max_right = 0;
        int res = 0;
        while (left < right) {
            if (height[left] < height[right]) {
                if (height[left] > max_left)
                    max_left = height[left];
                else res += (max_left - height[left]);
                left++;
            } else {
                if (height[right] > max_right)
                    max_right = height[right];
                else res += (max_right - height[right]);
                right--;
            }
        }
        return res;
    }
};

//栈
class Solution2 {
public:
    int trap(vector<int> &height) {
        stack<int> s;
        int cur = 0;
        int res = 0;
        while (cur < height.size()) {
            while (!s.empty() && height[cur] > height[s.top()]) {
                int top = s.top();
                s.pop();
                if (s.empty())
                    break;
                int distance = cur - s.top() - 1;
                int bound_height = min(height[cur], height[s.top()]) - height[top];
                res += distance * bound_height;
            }
            s.push(cur);
        }
        return res;
    }
};

class Solution3 {
public:
    int trap(vector<int> &height) {
        int left = 0;
        int right = height.size() - 1;
        int max_left = 0;
        int max_right = 0;
        int res = 0;
        while (left < right) {
            if (height[left] < height[right]) {
                if (height[left] > max_left)
                    max_left = height[left];
                else res += (max_left - height[left]);
                left++;
            } else {
                if (height[right] > max_right)
                    max_right = height[right];
                else res += (max_right - height[right]);
                right--;
            }
        }
        return res;
    }
};


class Solution4 {
public:
    int trap(vector<int> &height) {
        int n = height.size();
        int left = 0;
        int right = n - 1;
        int max_left = 0;
        int max_right = 0;
        int res = 0;
        while (left < right) {
            if (height[left] < height[right]) {
                if (height[left] > max_left)
                    max_left = height[left];
                else res += (max_left - height[left]);
                left++;
            } else {
                if (height[right] > max_right) {
                    max_right = height[right];
                } else res += (max_right - height[right]);
                right--;
            }
        }
        return res;
    }
};


//动态规划
class Solution5 {
public:
    int trap(vector<int> &height) {
        if (height.empty())
            return 0;
        int n = height.size();
        vector<int> max_left(n);
        vector<int> max_right(n);
        int res = 0;

        max_left[0] = height[0];
        for (int i = 1; i < n; ++i) {
            max_left[i] = max(max_left[i - 1], height[i]);
        }

        max_right[n - 1] = height[n - 1];
        for (int j = n - 2; j >= 0; j--) {
            max_right[j] = max(max_right[j + 1], height[j]);
        }

        for (int k = 0; k < n; ++k) {
            res += min(max_left[k], max_right[k]) - height[k];
        }
        return res;
    }
};


class Solution6 {
public:
    int trap(vector<int> &height) {
        stack<int> s;
        int cur = 0;
        int sum = 0;
        while (cur < height.size()) {
            while (!s.empty() && height[cur] > height[s.top()]) {
                int h = height[s.top()];
                s.pop();
                if (s.empty()) break;

                int distance = cur - s.top() - 1;
                int min_height = min(height[cur], height[s.top()]);
                sum += distance * (min_height - h);
            }
            s.push(cur++);
        }
        return sum;
    }
};