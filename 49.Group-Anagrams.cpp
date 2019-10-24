//
// Created by hqnddw on 2019/10/9.
//
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution1 {
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        unordered_map<string, vector<string>> map = {};
        vector<vector<string>> res;
        for (auto s:strs) {
            string t = s;
            sort(t.begin(), t.end());
            map[t].push_back(s);
        }
        for (auto p : map)
            res.push_back(p.second);
        return res;
    }
};


class Solution2 {
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> map{};
        for (auto s:strs) {
            string t = count_sort(s);
            map[t].push_back(s);
        }
        for (auto p : map)
            res.push_back(p.second);
        return res;
    }

    string count_sort(string s) {
        char count[26] = {0};
        for (auto c : s)
            count[c - 'a']++;
        string t;
        for (int i = 0; i < 26; ++i) {
            t += string(count[i], i + 'a');
        }
        return t;
    }
};


class Solution3 {
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        unordered_map<string, vector<string>> map{};
        vector<vector<string>> res;
        for (auto i : strs) {
            string key = string(i);
            sort(key.begin(), key.end());
            map[key].push_back(i);
        }
        for (auto i : map) {
            res.push_back(i.second);
        }

        return res;
    }
};


class Solution4 {
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> map;
        for (auto s :strs) {
            string tmp = s;
            sort(tmp.begin(), tmp.end());
            map[tmp].push_back(s);
        }
        for (auto i = map.begin(); i != map.end(); ++i) {
            res.push_back((*i).second);
        }
        return res;
    }
};