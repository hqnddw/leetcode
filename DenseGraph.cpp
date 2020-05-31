//
// Created by yida on 2020/5/16.
//

#include <iostream>
#include <vector>

using namespace std;

class DenseGraph {
private:
    int vertex, edge;
    bool directed;
    vector<vector<bool>> g;
public:
    DenseGraph(int vertex, bool directed) : vertex(vertex), directed(directed) {}
    ~DenseGraph(){}
    int V(){
        return vertex;
    }
    int E(){
        return edge;
    }
    bool hasEdge(int v, int w){
        return g[v][w];
    }
    void insertEdge(int v, int w){
        if (!hasEdge(v, w)){
            g[v][w] = true;
            if (!directed)
                g[w][v] = true;
        }
        edge++;
    }
};