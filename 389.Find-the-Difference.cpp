//
// Created by yida on 2020/5/27.
//
#include <string>

using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        int res = 0;
        string str = s + t;
        for (int i : str){
            res ^= i;
        }
        return res;
    }
};