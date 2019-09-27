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


