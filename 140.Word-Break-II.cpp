//
// Created by yida on 2020/4/16.
//
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, vector<string> &wordDict) {
        unordered_set<string> set(wordDict.begin(), wordDict.end());
        unordered_map<string, vector<string>> map;
        vector<string> res;
        return helper(s, set, map);
    }

    vector<string> helper(string &s, unordered_set<string> &set,
                          unordered_map<string, vector<string>> &map) {
        if (map.count(s))
            return map[s];
        vector<string> res;
        if (s.size() == 0)
            return res;
        for (int i = 0; i < s.size(); ++i) {
            string temp = s.substr(i);
            if (set.count(temp)){
                if (i == 0)
                   res.push_back(temp);
                else {
                    string str = s.substr(0, i);
                    vector<string> v = helper(str, set, map);
                    for (int j = 0; j < v.size(); ++j) {
                        res.push_back(v[j] + " " + temp);
                    }
                }
            }
        }
        map[s] = res;
        return res;
    }
};