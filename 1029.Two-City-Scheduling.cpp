//
// Created by hqnddw on 2020/6/4.
//
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>> &costs) {
        struct compare {
            bool operator()(vector<int> a, vector<int> b) {
                return a[0] - a[1] < b[0] - b[1];
            }
        };
        int res = 0;
        sort(costs.begin(), costs.end(), compare());
        for (int i = 0; i < costs.size() / 2; ++i) {
            res += costs[i][0] + costs[i + costs.size() / 2][1];
        }
        return res;
    }
};