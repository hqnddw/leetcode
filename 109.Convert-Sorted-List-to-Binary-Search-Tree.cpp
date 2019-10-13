//
// Created by hqnddw on 2019/10/7.
//
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};


class Solution1 {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        if (!head) return nullptr;
        ListNode *mid = findMiddle(head);
        TreeNode *root = new TreeNode(mid->val);
        if (head == mid)
            return root;
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(mid->next);
        return root;
    }

    ListNode *findMiddle(ListNode *head) {
        ListNode *pre = nullptr;
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && fast->next) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if (pre) pre->next = nullptr;
        return slow;
    }
};

class Solution2 {
public:

    TreeNode *sortedListToBST(ListNode *head) {
        vector<int> nums;
        listToarray(nums, head);
        return buildTree(nums, 0, nums.size() - 1);
    }

    void listToarray(vector<int> &nums, ListNode *head) {
        while (head) {
            nums.push_back(head->val);
            head = head->next;
        }
    }

    TreeNode *buildTree(vector<int> &nums, int left, int right) {
        if (left > right)
            return nullptr;
        int mid = (left + right) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        if (right == left)
            return root;
        root->left = buildTree(nums, left, mid - 1);
        root->right = buildTree(nums, mid + 1, right);
        return root;
    }
};


class Solution3 {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        if (!head)
            return nullptr;
        ListNode *middle = findMiddle(head);
        TreeNode *root = new TreeNode(middle->val);
        if (middle == head)
            return root;
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(middle->next);
        return root;
    }

    ListNode *findMiddle(ListNode *head) {
        ListNode *pre = nullptr;
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && fast->next) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if (pre)
            pre->next = nullptr;
        return slow;
    }
};


class Solution4 {
public:
    TreeNode *sortedListToBST(ListNode *head) {

        vector<int> res = linklistToArray(head);
        return buildTree(res, 0, res.size() - 1);
    }

    vector<int> linklistToArray(ListNode *head) {
        vector<int> v;
        while (head) {
            v.push_back(head->val);
            head = head->next;
        }
        return v;
    }

    TreeNode *buildTree(vector<int> &v, int start, int end) {
        if (start > end) return nullptr;
        int mid = (start + end) / 2;
        TreeNode *root = new TreeNode(v[mid]);
        root->left = buildTree(v, start, mid - 1);
        root->right = buildTree(v, mid + 1, end);
        return root;
    }
};