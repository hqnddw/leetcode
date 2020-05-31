//
// Created by yida on 2020/5/23.
//
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};

//bfs
class Solution1 {
public:
    int getImportance(vector<Employee *> employees, int id) {
        queue<int> q;
        int res = 0;
        unordered_map<int, int> map;
        q.push(id);
        while (!q.empty()) {
            id = q.front();
            q.pop();
            for (auto it : employees) {
                if (it->id == id) {
                    map[id] = it->importance;
                        for (int i : it->subordinates)
                            q.push(i);X
                }
            }
        }
        for (auto it : map) {
            res += it.second;
        }
        return res;
    }
};


//dfs
    class Solution {
    public:
        int getImportance(vector<Employee *> employees, int id) {
            unordered_set<int> set;
            int res = 0;
            for (auto it : employees) {
                if (it->id == id) {
                    if (!set.count(id)) {
                        res += it->importance;
                        set.insert(it->id);
                    }
                    for (int i : it->subordinates) {
                        res += getImportance(employees, i);
                    }
                    return res;
                }
            }
            return res;
        }
    };