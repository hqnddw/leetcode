//
// Created by hqnddw on 2019/11/5.
//
#include <string>
#include <unordered_map>

using namespace std;

class Solution1 {
public:
    int romanToInt(string s) {
        unordered_map<char, int> charToInt = {{'I', 1},
                                              {'V', 5},
                                              {'X', 10},
                                              {'L', 50},
                                              {'C', 100},
                                              {'D', 500},
                                              {'M', 1000}};
        int res = 0;
        int pre = 0;
        int index = s.size() - 1;
        while (index-- >= 0) {
            int cur = charToInt[s[index]];
            if (cur >= pre)
                res += cur;
            else res -= cur;
            pre = cur;
        }
        return res;
    }
};

class Solution2 {
public:
    int romanToInt(string s) {
        unordered_map<char, int> charToInt = {{'I', 1},
                                              {'V', 5},
                                              {'X', 10},
                                              {'L', 50},
                                              {'C', 100},
                                              {'D', 500},
                                              {'M', 1000}};
        int pre = 0;
        int i = 0;
        int sum = 0;
        for (int j = s.size() - 1; j > 0; --j) {
            int cur = charToInt[s[j]];
            if (cur >= pre)
                sum += cur;
            else sum -= cur;
            pre = cur;
        }
        return sum;
    }
};