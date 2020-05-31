//
// Created by yida on 2020/5/16.
//
#include <vector>

using namespace std;

class Solution1 {
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image,
                                  int sr, int sc, int newColor) {
        int val = image[sr][sc];
        vector<vector<bool>> visited(image.size(),
                                     vector<bool>(image[0].size(), false));
        dfs(image, sr, sc, newColor, val, visited);
        return image;
    }

    void dfs(vector<vector<int>> &image, int sr, int sc,
             int newColor, int val, vector<vector<bool>> &visited) {
        if (sr < 0 || sr >= image.size() || sc < 0 ||
            sc >= image[0].size() || visited[sr][sc] || image[sr][sc] != val)
            return;

        image[sr][sc] = newColor;
        visited[sr][sc] = true;
        dfs(image, sr - 1, sc, newColor, val, visited);
        dfs(image, sr + 1, sc, newColor, val, visited);
        dfs(image, sr, sc - 1, newColor, val, visited);
        dfs(image, sr, sc + 1, newColor, val, visited);
    }
};


class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image,
                                  int sr, int sc, int newColor) {
        int val = image[sr][sc];
        dfs(image, sr, sc, newColor, val);
        return image;
    }

    void dfs(vector<vector<int>> &image, int sr, int sc,
             int newColor, int val) {
        if (sr < 0 || sr >= image.size() || sc < 0 ||
            sc >= image[0].size() || image[sr][sc] != val)
            return;

        image[sr][sc] = newColor;
        dfs(image, sr - 1, sc, newColor, val);
        dfs(image, sr + 1, sc, newColor, val);
        dfs(image, sr, sc - 1, newColor, val);
        dfs(image, sr, sc + 1, newColor, val);
    }
};
