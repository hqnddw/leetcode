//
// Created by hqnddw on 2020/9/7.
//

#include <vector>
#include <iostream>

using namespace std;

void helper(vector<vector<int>> &graph, vector<bool> &visited, int start);

void dfs(int vertex, vector<vector<int>> edge) {
    vector<vector<int>> graph(vertex, vector<int>());
    for (auto v : edge) {
        graph[v[0]].push_back(v[1]);
    }
    vector<bool> visited(vertex, false);
    helper(graph, visited, 0);
}

void helper(vector<vector<int>> &graph, vector<bool> &visited, int start) {
    visited[start] = true;
    cout << start << " 已被遍历" << endl;
    for (int i : graph[start])
        if (!visited[i])
            helper(graph, visited, i);
}

int main() {
    vector<vector<int>> v{{0, 5},
                          {4, 3},
                          {0, 1},
                          {6, 4},
                          {5, 4},
                          {0, 2},
                          {0, 6},
                          {5, 3}};
    dfs(v.size(), v);
    return 0;
}