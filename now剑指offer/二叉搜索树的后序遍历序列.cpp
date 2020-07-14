//
// Created by hqnddw on 2019/10/21.
//
#include <vector>

using namespace std;

class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if (sequence.empty()) return false;
        return helper(sequence, 0, sequence.size() - 1);
    }

    bool helper(vector<int> &sequence, int lo, int hi) {
        if (lo >= hi) return true;
        int root = sequence[hi];
        int i;
        for (i = lo; i < hi; ++i) {
            if (sequence[i] > root)
                break;
        }
        int j;
        for (j = i; j < hi; ++j) {
            if (sequence[j] < root)
                return false;
        }
        bool left = helper(sequence, lo, i - 1);
        bool right = helper(sequence, i, hi - 1);
        return left && right;
    }
};