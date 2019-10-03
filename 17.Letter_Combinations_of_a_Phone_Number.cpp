//
// Created by hqnddw on 2019/9/12.
//
#include <vector>
#include <string>

using namespace std;


//回溯
class Solution1 {
public:
    const string map[10] = {
            " ",   //0
            "",    //1
            "abc", //2
            "def", //3
            "ghi", //4
            "jkl", //5
            "mno", //6
            "pqrs",//7
            "tuv", //8
            "wxyz",//9
    };

    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.empty())
            return res;
        findcombination(digits, res, "", 0);
        return res;
    }

    void findcombination(const string &digits, vector<string> &res, const string &s, int index) {
        if (index == digits.size()) {
            res.push_back(s);
            return;
        }
        string temp = map[digits[index] - '0'];
        for (int i = 0; i < temp.size(); ++i) {
            findcombination(digits, res, s + temp[i], index + 1);
        }
    }
};

//迭代
class Solution {
public:
    const string map[10] = {
            " ",   //0
            "",    //1
            "abc", //2
            "def", //3
            "ghi", //4
            "jkl", //5
            "mno", //6
            "pqrs",//7
            "tuv", //8
            "wxyz",//9
    };

    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.empty()) return res;
        res.push_back("");
        for (int i = 0; i < digits.size(); ++i) {
            string s = map[digits[i] - '0'];
            vector<string> temp;
            for (int j = 0; j < s.size(); ++j) {
                for (int k = 0; k < res.size(); ++k) {
                    temp.push_back(res[k] + s[j]);
                }
            }
            res = temp;
        }
        return res;
    }
};
