//
// Created by hqnddw on 2019/11/8.
//
#include <vector>

using namespace std;

class Solution1 {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.empty())
            return 0;
        int res = 0;
        int i = 0;
        while (i < prices.size() - 1) {
            while (i < prices.size() - 1 && prices[i] > prices[i + 1])
                i++;
            int valley = prices[i];
            while (i < prices.size() - 1 && prices[i] <= prices[i + 1])
                i++;
            int peak = prices[i];
            res += (peak - valley);
        }
        return res;
    }
};

class Solution2 {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.empty())
            return 0;
        int res = 0;
        for (int i = 0; i < prices.size() - 1; ++i) {
            if (prices[i + 1] > prices[i])
                res += (prices[i + 1] - prices[i]);
        }
        return res;
    }
};