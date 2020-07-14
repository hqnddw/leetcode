//
// Created by hqnddw on 2019/11/11.
//
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;

    TreeLinkNode(int x) : val(x), left(nullptr), right(nullptr), next(nullptr) {
    }
};

class Solution {
public:
    TreeLinkNode *GetNext(TreeLinkNode *pNode) {
        if (pNode->right) {
            TreeLinkNode *tmp = pNode->right;
            while (tmp->left) {
                tmp = tmp->left;
            }
            return tmp;
        }
        while (pNode->next) {
            TreeLinkNode *par = pNode->next;
            if (par->left == pNode)
                return par;
            pNode = pNode->next;
        }
        return nullptr;
    }
};