//
// Created by hqnddw on 2019/10/13.
//
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Solution1 {
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        vector<vector<int>> res;
        if (intervals.empty())
            return res;
        sort(intervals.begin(), intervals.end());
        res.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); ++i) {
            if (res.back()[1] >= intervals[i][0]) {
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            } else res.push_back(intervals[i]);
        }
        return res;
    }
};

class Solution2 {
public:
    struct compare {
        bool operator()(vector<int> &a, vector<int> &b) {
            return a[0] > b[0];
        }
    };

    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        vector<vector<int>> res;
        if (intervals.empty())
            return res;
        priority_queue<vector<int>, vector<vector<int>>, compare> pq;
        for (auto i:intervals)
            pq.push(i);
        res.push_back(pq.top());
        pq.pop();
        while (!pq.empty()) {
            auto temp = pq.top();
            pq.pop();
            if (res.back()[1] >= temp[0])
                res.back()[1] = max(res.back()[1], temp[1]);
            else res.push_back(temp);
        }
        return res;
    }
};


class Solution3 {
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        vector<vector<int>> res;
        if (intervals.empty()) return res;
        sort(intervals.begin(), intervals.end());
        res.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); ++i) {
            if (res.back()[1] >= intervals[i][0])
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            else res.push_back(intervals[i]);
        }
        return res;
    }
};