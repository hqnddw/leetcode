//
// Created by lwl on 2020/7/4.
//
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        s.erase(0, s.find_first_not_of(' '));
        s.erase(s.find_last_not_of(' ') + 1);
        bool numberseen = false;
        bool eseen = false;
        bool pointseen = false;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                numberseen = true;
            } else if (s[i] == '.') {
                if (pointseen || eseen)
                    return false;
                pointseen = true;
            } else if (s[i] == 'e') {
                if (!numberseen || eseen)
                    return false;
                eseen = true;
                numberseen = false;
            } else if (s[i] == '-' || s[i] == '+') {
                if (i != 0 && s[i - 1] != 'e')
                    return false;
            } else return false;
        }
        return numberseen;
    }
};