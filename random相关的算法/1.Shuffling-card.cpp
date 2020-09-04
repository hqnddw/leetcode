//
// Created by lwl on 2020/8/16.
//

#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <iostream>

using namespace std;

/**
 * 给定N张扑克牌和一个随机函数，设计一个洗牌算法
 * */

void shuffle(int nums[], int n) {
    if (n == 0)
        return;
    srand((unsigned) time(nullptr));
    for (int i = 0; i < n - 1; ++i) {
        int index = i + rand() % (n - i);
        swap(nums[i], nums[index]);
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    shuffle(arr, 8);
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;
}