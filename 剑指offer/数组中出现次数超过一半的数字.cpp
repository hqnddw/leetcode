//
// Created by hqnddw on 2019/11/17.
//
#include <vector>

using namespace std;

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if (numbers.empty()) return 0;
        int res = numbers[0];
        int times = 1;
        for (int i = 1; i < numbers.size(); ++i) {
            if (times == 0) {
                res = numbers[i];
                times = 1;
            } else if (res == numbers[i])
                times++;
            else times--;
        }
        int count = 0;
        for (int j = 0; j < numbers.size(); ++j) {
            if (numbers[j] == res)
                count++;
        }
        if (count * 2 <= numbers.size())
            return 0;
        return res;
    }
};