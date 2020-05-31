//
// Created by yida on 2020/5/17.
//
#include <vector>
#include <unordered_map>

using namespace std;

//最初思路
class Solution1 {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        unordered_map<char, int> map;
        int size = p.size();
        for (char c : p)
            map[c]++;
        for (int i = 0; i < s.size(); ++i) {
            if (map.count(s[i])) {
                if (helper(i, s, map, size))
                    res.push_back(i);
            }
        }
        return res;
    }

    bool helper(int start, const string &s, unordered_map<char, int> map, int size) {
        string tmp = s.substr(start, size);
        for (char c : tmp) {
            if (map.count(c)) return false;
            else {
                map[c]--;
                if (map[c] > 0)
                    return false;
            }
        }
        for (auto it : map) {
            if (it.second > 0)
                return false;
        }
        return true;
    }
};

//滑动窗口
class Solution2 {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        if (p.size() > s.size())
            return res;
        unordered_map<char, int> map;
        for (char c : p)
            map[c]++;
        int count = map.size();
        int start = 0;
        int end = 0;
        while (end < s.size()) {
            if (map.count(s[end])) {
                map[s[end]]--;
                if (map[s[end]] == 0) count--;
            }
            end++;
            while (count == 0) {
                if (map.count(s[start])) {
                    map[s[start]]++;
                    if (map[s[start]] > 0)
                        count++;
                }
                if (end - start == p.size())
                    res.push_back(start);
                start++;
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        if (p.size() > s.size())
            return res;
        unordered_map<char, int> map;
        for (char c : p)
            map[c]++;
        int count = p.size();
        int start = 0;
        int end = 0;
        while (end < s.size()) {
            if (map[s[end]] > 0)
                count--;
            map[s[end]]--;
            end++;

            if (count == 0)
                res.push_back(start);
            if (end - start == p.size()) {
                if (map[s[start]] >= 0)
                    count++;
                map[s[start]]++;
                start++;
            }
        }
        return res;
    }
};