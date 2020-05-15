//
// Created by hqnddw on 2020/5/6.
//
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

//双指针
class Solution1 {
public:
    bool isSubsequence(string s, string t) {
        int m = s.size();
        int n = t.size();
        int i = 0;
        int j = 0;
        while (i < m && j < n) {
            if (s[i] == t[j]) {
                i++;
                j++;
            } else {
                j++;
            }
        }
        return i == m;
    }
};


//binary search
class Solution {
public:
    bool isSubsequence(string s, string t) {
        unordered_map<char, vector<int>> map;
        for (int i = 0; i < t.size(); ++i) {
            map[t[i]].push_back(i);
        }
        int pre = -1;
        for (int j = 0; j < s.size(); ++j) {
            if (!map.count(s[j])) return false;
            auto it = upper_bound(map[s[j]].begin(), map[s[j]].end(), pre);
            if (it == map[s[j]].end()) return false;
            pre = *it;
        }
        return true;
    }
};