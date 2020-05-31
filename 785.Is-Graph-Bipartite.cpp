//
// Created by yida on 2020/5/28.
//
#include <vector>

using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>> &graph) {
        vector<int> colors(graph.size(), 0);
        for (int i = 0; i < graph.size(); ++i) {
            if (colors[i] == 0) {
                if (!dfs(graph, i, colors, 1))
                    return false;
            }
        }
        return true;
    }

    bool dfs(vector<vector<int>> &graph, int v, vector<int> &colors, int color) {
        if (colors[v] != 0)
            return colors[v] == color;
        colors[v] = color;
        for(auto i : graph[v]){
            if (!dfs(graph, i, colors, -color))
                return false;
        }
        return true;
    }
};