//
// Created by hqnddw on 2020/6/1.
//
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    int numBusesToDestination(vector<vector<int>> &routes, int S, int T) {
        unordered_map<int, vector<int>> map;
        unordered_set<int> visited;
        int res = 0;
        if (S == T) return res;
        for (int i = 0; i < routes.size(); ++i) {
            for (int j = 0; j < routes[i].size(); ++j) {
                map[routes[i][j]].push_back(i);
            }
        }
        queue<int> q;
        q.push(S);
        while (!q.empty()) {
            res++;
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                int cur = q.front();
                q.pop();
                for (auto bus : map[cur]) {
                    if (visited.count(bus))
                        continue;
                    visited.insert(bus);
                    for (auto v : routes[bus]) {
                        if (v == T) return res;
                        q.push(v);
                    }
                }
            }
        }
        return -1;
    }
};