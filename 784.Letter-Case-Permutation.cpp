//
// Created by yida on 2020/5/27.
//
#include <vector>
#include <string>
#include <queue>

using namespace std;

//bfs
class Solution1 {
public:
    vector<string> letterCasePermutation(string S) {
        queue<string> q;
        vector<string> res;
        if (S.empty()) return res;
        q.push(S);
        for (int i = 0; i < S.size(); ++i) {
            if (isdigit(S[i])) continue;
            int n = q.size();
            for (int j = 0; j < n; ++j) {
                string tmp = q.front();
                q.pop();

                tmp[i] = tolower(tmp[i]);
                q.push(tmp);
                tmp[i] = toupper(tmp[i]);
                q.push(tmp);
            }
        }
        while (!q.empty()) {
            string t = q.front();
            q.pop();
            res.push_back(t);
        }
        return res;
    }
};


class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> res;
        dfs(S, res, 0);
        return res;
    }

    void dfs(string &s, vector<string> &res, int pos) {
        if (pos == s.size()) {
            res.push_back(s);
            return;
        }
        if (isalpha(s[pos])) {
            s[pos] = toupper(s[pos]);
            dfs(s, res, pos + 1);
            s[pos] = tolower(s[pos]);
            dfs(s, res, pos + 1);
        } else {
            dfs(s, res, pos + 1);
        }
    }
};