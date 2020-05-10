//
// Created by hqnddw on 2020/5/2.
//
#include <vector>
#include <unordered_map>

using namespace std;

class Solution1 {
public:
    bool checkIfExist(vector<int> &arr) {
        for (int i = 0; i < arr.size(); ++i) {
            for (int j = 0; j != i && j < arr.size(); ++j) {
                if (arr[i] == 2 * arr[j] || 2 * arr[i] == arr[j])
                    return true;
            }
        }
        return false;
    }
};

class Solution {
public:
    bool checkIfExist(vector<int> &arr) {
        unordered_map<int, int> map;
        for (int i = 0; i < arr.size(); ++i) {
            map[arr[i]] = i;
        }
        for (int j = 0; j < arr.size(); ++j) {
            if (map.count(2 * arr[j]) && map[2 * arr[j]] != j)
                return true;
        }
        return false;
    }
};