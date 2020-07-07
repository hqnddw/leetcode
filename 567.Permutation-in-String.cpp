//
// Created by lwl on 2020/7/6.
//
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution1 {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> need;
        unordered_map<char, int> window;
        for (char c : s1)
            need[c]++;
        int left = 0, right = 0, valid = 0;
        while (right < s2.size()) {
            char c = s2[right];
            right++;
            if (need.count(c)) {
                window[c]++;
                if (window[c] == need[c])
                    valid++;
            }
            while (right - left >= s1.size()) {
                if (valid == need.size())
                    return true;
                char d = s2[left];
                left++;
                if (need.count(d)) {
                    if (window[d] == need[d])
                        valid--;
                    window[d]--;
                }
            }
        }
        return false;
    }
};

f