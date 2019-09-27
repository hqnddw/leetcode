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
class Solution2 {
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


class Solution3 {
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
        backtrack(digits, res, "", 0);
        return res;
    }

    void backtrack(string &digits, vector<string> &res, const string &s, int start) {
        if (start >= digits.size()) {
            res.push_back(s);
            return;
        }
        string temp = map[digits[start] - '0'];
        for (int j = 0; j < temp.size(); ++j) {
            backtrack(digits, res, s + temp[j], start + 1);
        }

    }

};


class Solution4 {
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
        for (int k = 0; k < digits.size(); ++k) {
            string temp = map[digits[k] - '0'];
            vector<string> v;
            for (auto i :res) {
                for (int j = 0; j < temp.size(); ++j) {
                    v.push_back(i + temp[j]);
                }
            }
            res = v;
        }
        return res;
    }
};


class Solution5 {
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
        string s = "";
        backtrack(res, s, digits, 0);
        return res;
    }

    void backtrack(vector<string> &res, const string &s, string digits, int start) {
        if (s.size() == digits.size()) {
            res.push_back(s);
            return;
        }
        string temp = map[digits[start] - '0'];
        for (int i = 0; i < temp.size(); ++i) {
            backtrack(res, s + temp[i], digits, start + 1);
        }
    }
};


class Solution6 {
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
        vector<string> re;
        if (digits.empty())
            return re;
        vector<string> res{""};
        for (int i = 0; i < digits.size(); ++i) {
            string str = map[digits[i] - '0'];
            vector<string> temp;

            for (int k = 0; k < str.size(); ++k) {
                for (auto j : res) {
                    j += str[k];
                    temp.push_back(j);
                }
            }
            res = temp;
        }
        return res;
    }
};