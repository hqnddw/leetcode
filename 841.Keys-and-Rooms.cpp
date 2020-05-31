//
// Created by yida on 2020/5/25.
//
#include <vector>
#include <queue>

using namespace std;

//dfs
class Solution1 {
public:
    bool canVisitAllRooms(vector<vector<int>> &rooms) {
        vector<int> visited(rooms.size(), false);
        helper(rooms, 0, visited);
        for (auto i : visited){
            if (!i) return false;
        }
        return true;
    }
    void helper(vector<vector<int>> &rooms, int id, vector<int> &visited){
        if (id == rooms.size())
            return;
        if (visited[id]) return;
        visited[id] = true;
        for (auto v : rooms[id]){
            helper(rooms, v, visited);
        }
    }
};

//bfs
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int> q;
        vector<bool> visited(rooms.size(), false);
        q.push(0);
        while (!q.empty()){
            int id = q.front();
            q.pop();
            if (visited[id]) continue;
            visited[id] = true;
            for (auto i : rooms[id])
                q.push(i);
        }
        for (auto i : visited){
            if (!i) return false;
        }
        return true;
    }
};