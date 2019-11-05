//
// Created by hqnddw on 2019/10/30.
//
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

//遇到重复的就开始从i处一步步的开始扫描
class Solution1 {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int i = 0, j = 0;
        int res = 0;
        unordered_set<char> set;
        while (i < n && j < n) {
            if (!set.count(s[j])) {
                set.insert(s[j++]);
                res = max(res, j - i);
            } else set.erase(s[i++]);
        }
        return res;
    }
};


//直接定位到重复的地方
class Solution2 {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0;
        int res = 0;
        unordered_map<char, int> map;
        for (int j = 0; j < s.size(); ++j) {
            if (map.count(s[j]))
                i = max(i, map[s[j]]);
            res = max(res, j - i + 1);
            map[s[j]] = j;
        }
        return res;
    }
};