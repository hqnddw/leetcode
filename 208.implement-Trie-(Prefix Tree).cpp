//
// Created by yida on 2020/5/15.
//
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

struct TrieNode {
    bool is_word;
    vector<TrieNode *> children;

    TrieNode() : is_word(false), children(26, nullptr) {}

    ~TrieNode() {
        for (auto child: children) {
            if (child) delete child;
        }
    }
};

class Trie {
public:
    /** Initialize your data structure here. */
    TrieNode *root;

    Trie() {
        root = new TrieNode();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *p = root;
        for (char c : word) {
            if (!p->children[c - 'a'])
                p->children[c - 'a'] = new TrieNode();
            p = p->children[c - 'a'];
        }
        p->is_word = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *p = find(word);
        return p && p->is_word;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return find(prefix) != nullptr;
    }

    TrieNode *find(string s) {
        TrieNode *p = root;
        for (char c : s) {
            p = p->children[c - 'a'];
            if (p == nullptr) break;
        }
        return p;
    }
};