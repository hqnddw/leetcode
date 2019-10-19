//
// Created by hqnddw on 2019/10/13.
//
#include <vector>
#include <algorithm>
#include <queue>
#include <forward_list>
#include <ext\slist>

using namespace std;

class Solution1 {
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval) {
        vector<vector<int>> res;
        if (intervals.empty() && newInterval.empty())
            return res;
        intervals.push_back(newInterval);
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
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval) {
        int i = 0;
        vector<vector<int>> res;
        while (i < intervals.size() && intervals[i][1] < newInterval[0])
            res.push_back(intervals[i++]);
        while (i < intervals.size() && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(intervals[i][0], newInterval[0]);
            newInterval[1] = max(intervals[i][1], newInterval[1]);
            i++;
        }
        res.push_back(newInterval);
        while (i < intervals.size())
            res.push_back(intervals[i++]);
        return res;
    }
};


class Solution3 {
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval) {
        vector<vector<int>> res;
        if (intervals.empty() && newInterval.empty())
            return res;
        int i = 0;
        while (i < intervals.size() && intervals[i][1] < newInterval[0])
            res.push_back(intervals[i++]);
        while (i < intervals.size() && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(intervals[i][0], newInterval[0]);
            newInterval[1] = max(intervals[i][1], newInterval[1]);
            i++;
        }
        res.push_back(newInterval);
        while (i < intervals.size())
            res.push_back(intervals[i++]);
        return res;
    }
};