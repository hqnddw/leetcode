//
// Created by hqnddw on 2019/10/29.
//
#include <stack>
#include <queue>
#include <string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        string s;
        s = s + "[";
        queue<TreeNode *> q;
        if (!root) return "";
        q.push(root);
        while (!q.empty()) {
            root = q.front();
            q.pop();
            if (root) {
                s += root->val;
                q.push(root->left);
                q.push(root->right);
            } else s += "null";
            s += ",";
        }
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {

    }
};
