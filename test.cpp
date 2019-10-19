#include <iostream>
#include <cstdio>
#include <vector>
#include <cstddef>

using namespace std;

class Solution {
public:
    vector<int> helper(vector<int> &res, vector<int> &deadline, vector<int> &cost) {
        int curTime = 9;
        int curRes = 0;
        vector<int> v;
        backtrack(cost, v, res, deadline, curRes, curTime, 0);
        return v;
    }

    void backtrack(vector<int> &cost, vector<int> &v, vector<int> &res,
                   vector<int> &deadline, int curRes, int curTime, int start) {
        if (curTime + cost[start] > deadline[start] && curTime + cost[start] > 17) {
            v.push_back(curRes);
            return;
        }
        for (int i = start; i < cost.size(); ++i) {
            if (curTime + cost[i] <= deadline[i] && curTime + cost[i] <= 17)
                curRes += res[i];
            backtrack(cost, v, res, deadline, curRes, curTime, i + 1);
            if (curTime + cost[i] <= deadline[i] && curTime + cost[i] <= 17)
                curRes -= res[i];
        }
    }
};

int main() {
    vector<int> res;
    vector<int> deadline;
    vector<int> cost;
    vector<int> v;
    int a;
    cin >> a;
    while (a--) {
        int b, c, d;
        cin >> b >> c >> d;
        res.push_back(b);
        deadline.push_back(c);
        cost.push_back(d);
    }
    Solution s;
    s.helper(res, deadline, cost);
    cout << v.size() << endl;
    return 0;
}