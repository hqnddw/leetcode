//
// Created by yida on 2020/5/25.
//
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;


//Djikstra
class Solution1 {
public:
    int networkDelayTime(vector<vector<int>> &times, int N, int K) {
        struct compare {
            bool operator()(pair<int, int> a, pair<int, int> b) {
                return a.first < b.first;
            }
        };
        vector<bool> visited(N + 1, false);
        unordered_map<int, unordered_map<int, int>> map;
        for (auto v : times) {
            map[v[0]][v[1]] = v[2];
        }
        int res = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
        pq.push({0, K});
        while (!pq.empty()) {
            auto curNode = pq.top();
            pq.pop();
            int vertex = curNode.second;
            int dist = curNode.first;
            if (visited[vertex]) continue;
            visited[vertex] = true;
            res = dist;
            N--;
            for (auto it : map[vertex]) {
                pq.push({dist + it.second, it.first});
            }
        }
        return N == 0 ? res : -1;
    }
};

//Bellman Ford
class Solution {
public:
    int networkDelayTime(vector<vector<int>> &times, int N, int K) {
        int u, v, w;
        vector<int> dist(N + 1, INT_MAX);
        dist[K] = 0;
        for (int i = 0; i < N; ++i) {
            for (auto it : times) {
                u = it[0], v = it[1], w = it[2];
                if (dist[u] != INT_MAX)
                    dist[v] = min(dist[v], dist[u] + w);
            }
        }
        int res = INT_MIN;
        for (int j = 1; j < dist.size(); ++j) {
            res = max(dist[j], res);
        }
        return res == INT_MAX ? -1 : res;
    }
};