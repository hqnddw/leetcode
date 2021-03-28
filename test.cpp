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
#include <cstring>
#include <thread>
#include <sstream>
#include <stdlib.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int main() {
    string s = "早餐太差，无论去多少人，那边也不加食品的。酒店应该重视一下这个问题了。房间本身很好";
    cout<<s<<endl;
    cout << s.find("早餐") << endl;
}