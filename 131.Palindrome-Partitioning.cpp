#include <vector>
#include <string>

using namespace std;

//回溯法
class Solution1 {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> v;
        dfs(res, v, s, 0);
        return res;
    }

    void dfs(vector<vector<string>> &res, vector<string> &v, const string &s, int index) {
        if (index == s.size()) {
            res.push_back(v);
            return;
        }
        for (int i = index; i < s.size(); ++i) {
            if (helper(s, index, i)) {
                v.push_back(s.substr(index, i - index + 1));
                dfs(res, v, s, i + 1);
                v.pop_back();
            }
        }
    }

    bool helper(const string &s, int start, int end) {
        while (start <= end) {
            if (s[start] != s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }
};


class Solution2 {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> v;
        dfs(s, res, v, 0);
        return res;
    }

    void dfs(string &s, vector<vector<string>> &res, vector<string> &v, int start) {
        if (start == s.size()) {
            res.push_back(v);
            return;
        }
        for (int i = start; i < s.size(); ++i) {
            if (helper(s, start, i)) {
                v.push_back(s.substr(start, i - start + 1));
                dfs(s, res, v, i + 1);
                v.pop_back();
            }
        }
    }

    bool helper(string &s, int left, int right) {
        while (left <= right) {
            if (s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
};