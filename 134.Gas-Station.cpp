//
// Created by hqnddw on 2020/4/12.
//
#include <vector>

using namespace std;

//暴力法
class Solution1 {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int n = gas.size();
        for (int i = 0; i < n; ++i) {
            int j = i;
            int remain = gas[i];
            while (remain - cost[j] >= 0) {
                remain += (gas[(j + 1) % n] - cost[j]);
                j = (j + 1) % n;
                if (j == i)
                    return i;
            }
        }
        return -1;
    }
};

//暴力法的优化
class Solution2 {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int n = gas.size();
        for (int i = 0; i < n; ++i) {
            int j = i;
            int remain = gas[i];
            while (remain - cost[j] >= 0) {
                remain += (gas[(j + 1) % n] - cost[j]);
                j = (j + 1) % n;
                if (j == i)
                    return i;
            }
            if (i > j)
                return -1;
            i = j;
        }
        return -1;
    }
};

// 1.If the total number of gas is bigger than the total number of cost. There must be a solution.
// 2.If car starts at A and can not reach B. Any station between A and B
//   can not reach B.(B is the first station that A can not reach.)
class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int totalGas = 0;
        int totalCost = 0;
        int res = 0;
        for (int i = 0; i < gas.size(); ++i) {
            res += (gas[i] - cost[i]);
        }
        if (res < 0) return -1;
        int tank = 0;
        int start = 0;
        for (int j = 0; j < gas.size(); ++j) {
            tank += (gas[j] - cost[j]);
            if (tank < 0) {
                tank = 0;
                start = j + 1;
            }
        }
        return start;
    }
};