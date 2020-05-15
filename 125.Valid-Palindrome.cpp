//
// Created by hqnddw on 2020/4/4.
//
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;
        while (left <= right) {
            char c1 = s[left];
            char c2 = s[right];
            if (!isalnum(c1))
                left++;
            else if (!isalnum(c2))
                right--;
            else if (tolower(c1) != tolower(c2))
                return false;
            left++;
            right--;
        }
        return true;
    }
};