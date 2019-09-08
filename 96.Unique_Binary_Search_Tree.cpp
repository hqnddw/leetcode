//
// Created by hqnddw on 2019/8/28.
//
#include <vector>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution1 {
public:
    int numTrees(int n) {
        vector<int> v;
        v.push_back(1);
        v.push_back(1);
        for (int i = 2; i < n + 1; ++i) {
            int temp = 0;
            for (int j = 1; j <= i; ++j) {
                temp += v[j - 1] * v[i - j];
            }
            v.push_back(temp);
        }
        return v[n];
    }
};


//第三次
class Solution2 {
public:
    int numTrees(int n) {
        vector<int> v;
        v.push_back(1);
        v.push_back(1);
        int temp;
        for (int i = 2; i <= n; ++i) {
            temp = 0;
            for (int j = 1; j <= i; ++j) {
                temp += v[j - 1] * v[i - j];
            }
            v.push_back(temp);
        }
        return v[n];
    }
};


class Solution {
public:
    int numTrees(int n) {
        vector<int> v;
        v.push_back(1);
        v.push_back(1);
        for (int i = 2; i <= n; ++i) {
            int temp = 0;
            for (int j = 1; j <= i; ++j) {
                temp += v[j - 1] * v[i - j];
            }
            v.push_back(temp);
        }
        return v[n];
    }
};