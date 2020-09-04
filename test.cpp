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

// Definition for a Node.
class Node {
public:
    int val;
    Node *prev;
    Node *next;
    Node *child;
};


template<class ... Types>
void f(Types... args){

}

int main(){
    f();
    f(1);
    f
}
