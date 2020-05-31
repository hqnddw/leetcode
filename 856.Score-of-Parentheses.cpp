//
// Created by yida on 2020/5/21.
//
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    int scoreOfParentheses(string S) {
        int cur = 0;
        stack<int> s;
        for (char c : S){
            if (c == '('){
                s.push(cur);
                cur = 0;
            } else {
                cur += s.top() + max(cur, 1);
                s.pop();
            }
        }
        return cur;
    }
};