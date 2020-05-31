//
// Created by yida on 2020/5/24.
//
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
        queue<int> q;
        vector<int> res;
        int count = numCourses;
        vector<vector<int>> adj(numCourses);
        vector<int> degrees(numCourses, 0);
        for (auto v : prerequisites) {
            adj[v[1]].push_back(v[0]);
            degrees[v[0]]++;
        }
        for (int i = 0; i < degrees.size(); ++i) {
            if (degrees[i] == 0)
                q.push(i);
        }
        while (!q.empty()) {
            int vertex = q.front();
            q.pop();
            count--;
            res.push_back(vertex);
            for (auto i : adj[vertex]) {
                degrees[i]--;
                if (degrees[i] == 0)
                    q.push(i);
            }
        }
        return (count == 0) ? res : vector<int>();
    }
};