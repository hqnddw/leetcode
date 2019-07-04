//
// Created by hqnddw on 2019/7/4.
//
#include <queue>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int openLock(vector<string> &deadends, string target) {
        unordered_set<string> visited;
        for (const auto &i : deadends)
            visited.insert(i);
        string begin = "0000";
        if (visited.count(begin))
            return -1;
        queue<pair<string, int>> q;
        q.push({begin, 0});
        while (!q.empty()) {
            auto t = q.front();
            if (t.first == target)
                return t.second;
            q.pop();

            for (int i = 0; i < 4; ++i) {
                for (int j = -1; j <= 1; j += 2) {
                    string temp = t.first;
                    if (j == -1 && temp[i] == '0')
                        temp[i] = '9';
                    else if (j == 1 && temp[i] == '9')
                        temp[i] = '0';
                    else temp[i] += j;
                    if (visited.count(temp)) continue;
                    else {
                        q.push({temp, t.second + 1});
                        visited.insert(temp);
                    }
                }

            }

        }
        return -1;
    }
};
