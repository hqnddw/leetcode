//
// Created by yida on 2020/5/21.
//
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        vector<int> res;
        int min = INT_MAX;
        for (int i = 0; i < prices.size(); ++i) {
            if (prices[i] < min)
                min = prices[i];
            else {
                int tmp = 0;
                while (i < prices.size() && prices[i] > min) {
                    tmp = max(tmp, prices[i] - min);
                }
                i--;
                res.push_back(tmp);
                min = INT_MAX;
            }
        }
        if (res.empty()) return 0;
        if (res.size() == 1) return res.back();
        else {
            sort(res.begin(), res.end());
            return res[res.size() - 1] + res[res.size() - 2];
        }
    }
};