#include <string>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <set>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Definition for a Node.
class Node {
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    int search(vector<int> &nums, int x) {
        int lo = 0, hi = nums.size();
        vector<int> res;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (nums[mid] > x)
                hi = mid;
            else lo = mid + 1;
        }
        return nums[--lo];
    }
};

int main() {
    vector<int> nums{1, 2, 3, 4, 5};
    Solution s;
    cout << s.search(nums, 3) << endl;
}