//
// Created by hqnddw on 2020/4/4.
//
#include <string>
#include <unordered_set>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
        unordered_set<string> set(wordList.begin(), wordList.end());
        queue<string> q;
        q.push(beginWord);
        int level = 1;
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                string word = q.front();
                q.pop();
                if (word == endWord)
                    return level;
                for (int j = 0; j < word.size(); ++j) {
                    char c = word[j];
                    for (int k = 0; k < 26; ++k) {
                        word[j] = 'a' + k;
                        if (set.find(word) != set.end()) {
                            q.push(word);
                            set.erase(word);
                        }

                    }
                    word[j] = c;
                }
            }
            level++;
        }
        return 0;
    }
};
