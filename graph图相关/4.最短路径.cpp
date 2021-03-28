//
// Created by hqnddw on 2020/9/7.
//
#include <vector>
#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

/**
 * Dijkstra 算法
 * */

class Solution {
public:
    int networkDelayTime(vector<vector<int>> &times, int N, int K) {
        unordered_map<int, unordered_map<int, int>> graph;
        for (auto v : times) {
            graph[v[0]].insert({v[1], v[2]});
        }
        struct compare {
            bool operator()(pair<int, int> a, pair<int, int> b) {
                return a.first > b.first;
            }
        };
        int res = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
        pq.push({0, K});
        vector<bool> visited(N + 1, false);

        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            int node = cur.second;
            int dist = cur.first;
            if (visited[node]) continue;
            N--;
            visited[node] = true;
            res = dist;
            for (auto i : graph[node]) {
                pq.push({dist + i.second, i.first});
            }
        }
        return N == 0 ? res : -1;
    }
};