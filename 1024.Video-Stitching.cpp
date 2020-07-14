//
// Created by lwl on 2020/7/14.
//
#include <vector>
#include <algorithm>

using namespace std;

class Solution1 {
public:
    int videoStitching(vector<vector<int>> &clips, int T) {
        sort(clips.begin(), clips.end());
        int res = 0;
        for (int i = 0, start = 0, end = 0; start < T; start = end, ++res) {
            while (i < clips.size() && clips[i][0] <= start) {
                end = max(end, clips[i][1]);
                i++;
            }
            if (start == end) return -1;
        }
        return res;
    }
};


class Solution {
public:
    int videoStitching(vector<vector<int>> &clips, int T) {
        vector<vector<int>> dp(T + 1, vector<int>(T + 1, 102));
        for (auto v : clips) {
            int start = v[0];
            int end = v[1];
            for (int l = 1; l <= T; ++l) {
                for (int i = 0; i <= T - l; ++i) {
                    int j = i + l;
                    if (start > j || end < i) continue;
                    if (start <= i && end >= j) dp[i][j] = 1;
                    else if (end >= j) dp[i][j] = min(dp[i][j], dp[i][start] + 1);
                    else if (start <= i) dp[i][j] = min(dp[i][j], dp[end][j] + 1);
                    else dp[i][j] = min(dp[i][j], dp[i][start] + dp[end][j] + 1);
                }
            }
        }
        return dp[0][T] == 102 ? -1 : dp[0][T];
    }
};