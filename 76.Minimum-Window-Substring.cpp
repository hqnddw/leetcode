//
// Created by lwl on 2020/7/6.
//
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need;
        unordered_map<char, int> window;
        for (char c :t)
            need[c]++;
        int res = INT_MAX, left = 0, right = 0, valid = 0, start = 0;
        while (right < s.size()) {
            char c = s[right];
            right++;
            if (need.count(c)) {
                //window[c]>=need[c]
                window[c]++;
                if (need[c] == window[c])
                    valid++;
            }
            while (valid == need.size()) {
                if (right - left < res) {
                    start = left;
                    res = right - left;
                }
                char d = s[left];
                left++;
                if (need.count(d)) {
                    if (window[d] == need[d])
                        valid--;
                    window[d]--;
                }
            }
        }
        return res == INT_MAX ? "" : s.substr(start, res);
    }
};
