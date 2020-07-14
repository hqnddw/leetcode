//
// Created by hqnddw on 2019/10/21.
//
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    bool IsPopOrder(vector<int> pushV, vector<int> popV) {
        int j = 0;
        int n = pushV.size();
        stack<int> s;
        for (auto i:pushV) {
            s.push(i);
            while (!s.empty() && j < n && s.top() == popV[j]) {
                s.pop();
                j++;
            }
        }
        return s.empty();
    }
};