//
// Created by hqnddw on 2019/10/26.
//
#include <string>
#include <unordered_map>

using namespace std;

class Solution1 {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> map;
        for (char c:s) {
            if (map.count(c))
                map[c] += 1;
            else map[c] = 1;
        }
        unordered_map<char, int>::iterator i;
        for (int j = 0; j < s.size(); ++j) {
            if (map[s[j]] == 1)
                return j;
        }
        return -1;
    }
};

class Solution2 {
public:
    int firstUniqChar(string s) {
        int map[26] = {0};
        for (char c: s) {
            map[c - 'a'] += 1;
        }
        for (int i = 0; i < s.size(); ++i) {
            if (map[s[i] - 'a'] == 1)
                return i;
        }
        return -1;
    }
};


class Solution3 {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> map;
        for (char c:s) {
            if (map.count(c))
                map[c] += 1;
            else map[c] = 1;
        }
        for (int i = 0; i < s.size(); ++i) {
            if (map[s[i]] == 1)
                return i;
        }
        return -1;
    }
};