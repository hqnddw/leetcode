//
// Created by yida on 2020/4/16.
//
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

//备忘录法
class Solution1 {
public:
    bool wordBreak(string s, vector<string> &wordDict) {
        unordered_set<string> set(wordDict.begin(), wordDict.end());
        unordered_map<string, bool> map;
        return helper(s, set, map);
    }

    bool helper(string &s, unordered_set<string> &set, unordered_map<string, bool> &map) {
        if (s == "")
            return true;
        if (map.count(s))
            return map[s];
        for (int i = 0; i < s.size(); ++i) {
            string left = s.substr(0, i);
            string right = s.substr(i);
            if (set.count(right) && helper(left, set, map)) {
                map[s] = true;
                return true;
            }
        }
        map[s] = false;
        return false;
    }
};


//动态规划法
class Solution {
public:
    bool wordBreak(string s, vector<string> &wordDict) {
        vector<bool> dp(s.size() + 1, false);
        unordered_set<string> set(wordDict.begin(), wordDict.end());
        dp[0] = true;
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = i-1; j >= 0; --j) {
                string temp = s.substr(j, i-j);
                if (dp[j] && set.find(temp) != set.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};