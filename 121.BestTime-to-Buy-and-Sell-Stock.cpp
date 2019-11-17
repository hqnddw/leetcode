//
// Created by hqnddw on 2019/11/7.
//
#include <vector>
#include <climits>

using namespace std;

class Solution1 {
public:
    int maxProfit(vector<int> &prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;
        for (auto i:prices) {
            if (i < minPrice)
                minPrice = i;
            else if (i - minPrice > maxProfit)
                maxProfit = i - minPrice;
        }
        return maxProfit;
    }
};


class Solution2 {
public:
    int maxProfit(vector<int> &prices) {
        int dp = prices[0];
        int maximum = prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            int num = prices[i] - prices[i - 1];
            if (dp > 0)
                dp = dp + num;
            else dp = num;
            maximum = max(maximum, dp);
        }
        return maximum;
    }
};