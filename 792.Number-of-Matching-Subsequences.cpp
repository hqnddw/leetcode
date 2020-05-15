//
// Created by hqnddw on 2020/5/6.
//
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numMatchingSubseq(string S, vector<string> &words) {
        int res = 0;
        vector<vector<int >> map(26);
        for (int i = 0; i < S.size(); ++i) {
            map[S[i] - 'a'].push_back(i);
        }
        for (auto &s : words) {
            int pre = -1;
            bool flag = true;
            for (char c : s) {
                auto it = upper_bound(map[c - 'a'].begin(), map[c - 'a'].end(), pre);
                if (it == map[c - 'a'].end()) {
                    flag = false;
                    break;
                } else pre = *it;
            }
            if (flag) res++;
        }
        return res;
    }
};