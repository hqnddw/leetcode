//
// Created by hqnddw on 2019/11/13.
//
#include <vector>
#include <algorithm>

using namespace std;

//插入排序思想
class Solution1 {
public:
    void reOrderArray(vector<int> &array) {
        int k = 0;
        for (int i = 0; i < array.size(); ++i) {
            if (array[i] & 1) {
                int j = i;
                while (j > k) {
                    swap(array[j], array[j - 1]);
                    j--;
                }
                k++;
            }
        }
    }
};


class Solution2 {
public:
    void reOrderArray(vector<int> &array) {
        vector<int>::iterator it = array.begin();
        for (int i = 0; i < array.size(); ++i) {
            if ((*it & 1) == 0) {
                int temp = *it;
                array.erase(it);
                array.push_back(temp);
            } else it++;
        }
    }
};

bool func(int i) {
    return ((i & 1) == 1);
}

class Solution {
public:
    void reOrderArray(vector<int> &array) {

        stable_partition(array.begin(), array.end(), func);
    }
};