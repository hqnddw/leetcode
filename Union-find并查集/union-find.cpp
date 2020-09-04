//
// Created by lwl on 2020/8/15.
//

/**
 *  并查集是一种树型的数据结构，用于处理一些不相交集合（Disjoint Sets）的合并及查询问题。
 *  常常在使用中以森林来表示。
 *  应用：
 *      1.用来合并集合元素，并确定结合数量，查寻元素属于哪个集合。
        2.在图结构里（图里的点便是元素），确定两点是否处于联通状态，
 * */
#include <vector>
#include <unordered_set>
using namespace std;

class UnionFind {
public:
    UnionFind(int n) {
        parent = vector<int>(n + 1, 0);
        rank = vector<int>(n + 1, 0);
        for (int i = 0; i <= n; ++i) {
            parent[i] = i;
        }
    }

    bool Union(int u, int v) {
        int pu = Find(u);
        int pv = Find(v);
        if (pu == pv) return false; //在同一集合内
        if (rank[pu] > rank[pv]) {
            parent[pv] = pu;
        } else if (rank[pv] > rank[pu])
            parent[pu] = pv;
        else {
            parent[pv] = pu;
            rank[pu]++;
        }
        return true;
    }

    int Find(int v) {
        if (parent[v] != v) {
            parent[v] = Find(parent[v]);
        }
        return parent[v];
    }

private:
    vector<int> parent;
    vector<int> rank;
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        UnionFind uf(n);
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n ; ++j) {
                if (M[i][j] == 1) uf.Union(i, j);
            }
        }
        unordered_set<int> set;
        for (int i = 0; i < n; ++i) {
            set.insert(uf.Find(i));
        }
        return set.size();
    }
};