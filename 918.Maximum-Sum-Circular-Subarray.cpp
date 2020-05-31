//
// Created by yida on 2020/5/17.
//
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int> &A) {
        int resMax = A[0];
        int resMin = A[0];
        int dpMax = A[0];
        int dpMin = A[0];
        int sum = A[0];
        for (int i = 1; i < A.size(); ++i) {
            dpMax = max(dpMax + A[i], A[i]);
            resMax = max(resMax, dpMax);

            dpMin = min(A[i], dpMin + A[i]);
            resMin = min(resMin, dpMin);

            sum += A[i];
        }
        if (resMin == sum) return resMax;
        return max(resMax, sum - resMin);
    }
};
