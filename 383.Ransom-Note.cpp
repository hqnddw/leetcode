//
// Created by hqnddw on 2020/5/3.
//
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> map;
        for (char c: magazine)
            map[c]++;
        for (char c : ransomNote) {
            if (!map.count(c) || map[c] == 0)
                return false;
            map[c]--;
        }
        return true;
    }
};
