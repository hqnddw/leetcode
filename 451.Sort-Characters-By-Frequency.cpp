//
// Created by yida on 2020/5/22.
//
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        string res;
        struct compare {
            bool operator()(pair<char, int> a, pair<char, int> b){
                return a.second < b.second;
            }
        };
        priority_queue<pair<char, int>, vector<pair<char, int>>, compare> pq;
        unordered_map<char, int> map;
        for (char c: s)
            map[c]++;
        for (auto it : map){
            pq.push(it);
        }
        while (!pq.empty()){
            auto tmp = pq.top();
            pq.pop();
            for (int i = 0; i < tmp.second; ++i) {
                res += tmp.first;
            }
        }
        return res;
    }
};