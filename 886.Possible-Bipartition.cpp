//
// Created by yida on 2020/5/28.
//
#include <vector>
#include <queue>

#define WHITE 0
#define RED 1
#define BLUE 2
using namespace std;

//bfs
class Solution1 {
public:
    bool possibleBipartition(int N, vector<vector<int>> &dislikes) {
        queue<int> q;
        vector<vector<int>> g(N + 1);
        vector<int> color(N + 1, WHITE);
        vector<bool> visited(N + 1, false);
        for (auto v: dislikes) {
            int u = v[0];
            int w = v[1];
            g[u].push_back(w);
            g[w].push_back(u);
        }
        for (int i = 1; i <= N; ++i) {
            if (!visited[i]) {
                color[i] = RED;
                q.push(i);
                while (!q.empty()) {
                    int vertex = q.front();
                    q.pop();
                    if (visited[vertex])
                        continue;
                    visited[vertex] = true;
                    for (auto v : g[vertex]) {
                        if (color[v] == color[vertex])
                            return false;
                        if (color[vertex] == RED)
                            color[v] = BLUE;
                        else color[v] = RED;
                        q.push(v);
                    }
                }
            }
        }
        return true;
    }
};


class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>> &dislikes) {
        vector<vector<int>> g(N + 1);
        vector<int> colors(N + 1, 0);
        for (auto v : dislikes) {
            g[v[0]].push_back(v[1]);
            g[v[1]].push_back(v[0]);
        }
        for (int i = 1; i <= N; ++i) {
            if (colors[i] == 0 && !dfs(g, colors, 1, i))
                return false;
        }
        return true;
    }

    bool dfs(vector<vector<int>> &g, vector<int> &colors, int color, int v) {
        if (colors[v] != 0)
            return colors[v] == color;
        colors[v] = color;
        for (auto i : g[v]) {
            if (!dfs(g, colors, -color, i))
                return false;
        }
        return true;
    }
};