//
// Created by yida on 2020/5/20.
//
#include <vector>
#include <climits>
#include <stack>

using namespace std;

class StockSpanner {
public:
    stack<int> s;
    vector<int> v;
    int index = 0;

    StockSpanner() {

    }

    int next(int price) {
        v.push_back(price);
        int res = 1;
        if (s.empty()) {
            s.push(index);
            index++;
            return res;
        } else {
            while (!s.empty() && price >= v[s.top()]) {
                s.pop();
            }
            res = s.empty() ? index + 1 : index - s.top();
            s.push(index);
            index++;
            return res;
        }
    }
};

