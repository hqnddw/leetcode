//
// Created by yida on 2020/5/24.
//
#include <vector>
#include <queue>

using namespace std;

//bfs
class Solution1 {
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        graph g = buildGraph(numCourses, prerequisites);
        vector<int> degrees = computeIndegrees(g);
        for (int i = 0; i < numCourses; ++i) {
            int j = 0;
            for (; j < numCourses; j++) {
                if (degrees[j] == 0) {
                    break;
                }
            }
            if (j == numCourses)
                return false;
            degrees[j]--;
            for (int v : g[j])
                degrees[v]--;
        }
        return true;
    }


private:
    typedef vector<vector<int>> graph;

    graph buildGraph(int numCourses, vector<vector<int>> &prerequisites) {
        graph g(numCourses);
        for (auto v : prerequisites) {
            g[v[1]].push_back(v[0]);
        }
        return g;
    }

    vector<int> computeIndegrees(graph &g) {
        vector<int> degrees(g.size(), 0);
        for (auto v : g) {
            for (int i :v)
                degrees[i]++;
        }
        return degrees;

    }
};


//拓扑排序
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        queue<int> q;
        int res = numCourses;
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
            res--;
            for (int i : adj[vertex]) {
                degrees[i]--;
                if (degrees[i] == 0)
                    q.push(i);
            }
        }
        return res == 0;
    }
};