#include <string>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <set>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Definition for a Node.
class Node {
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    int networkDelayTime(vector<vector<int>> &times, int N, int K) {
        struct compare {
            bool operator()(pair<int, int> a, pair<int, int> b) {
                return a.second > b.second;
            }
        };
        vector<vector<pair<int, int>>> g(N + 1);
        vector<bool> visited(N + 1, false);
        for (auto v : times) {
            g[v[0]].push_back({v[2], v[1]});
        }
        int res = 0;
        priority_queue<pair<int, int>, vector<pair<int, int >>, greater<>> pq;

        pq.push({0, K});
        while (!pq.empty()) {
            auto node = pq.top();
            pq.pop();
            int dist = node.first;
            int vertex = node.second;
            if (visited[vertex]) continue;
            visited[vertex] = true;
            N--;
            if (N == 0)
                return res;
            res = dist;
            for (auto v :g[vertex]) {
                pq.push({v.first + dist, v.second});
            }
        }
        return N == 0 ? res : -1;
    }
};