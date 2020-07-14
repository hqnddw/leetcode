//
// Created by yida on 2020/5/20.
//
#include <vector>
#include <cmath>
#include <iostream>
#include <climits>

using namespace std;
/*Given a set of integers, the task is to divide it into two sets S1 and S2 such that
the absolute difference between their sums is minimum.
 Input:  arr[] = {1, 6, 11, 5}
 Output: 1
 Explanation:
 Subset1 = {1, 5, 6}, sum of Subset1 = 12
 Subset2 = {11}, sum of Subset2 = 11
 */

int findMin(vector<int> &nums) {
    int sum = 0;
    for (int i : nums) {
        sum += i;
    }
    vector<vector<bool> > dp(nums.size() + 1, vector<bool>(sum + 1, false));
    for (int k = 0; k <= nums.size(); ++k) {
        dp[k][0] = true;
    }
    for (int j = 1; j <= nums.size(); ++j) {
        for (int i = 1; i <= sum; ++i) {
            if (i >= nums[j - 1])
                dp[j][i] = dp[j - 1][i] || dp[j - 1][i - nums[j - 1]];
            else dp[j][i] = dp[j - 1][i];
        }
    }
    int diff = -1;
    for (int l = sum/2; l >= 0; --l) {
        if (dp[nums.size()][l]){
            diff = sum - 2 * l;
            break;
        }
    }
    return diff;
}


int main() {
    int N;
    cin >> N;
    vector<int> v;
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        while (a) {
            int c;
            cin >> c;
            v.push_back(c);
            a--;
        }
        cout << findMin(v) << endl;
    }
    return 0;
};