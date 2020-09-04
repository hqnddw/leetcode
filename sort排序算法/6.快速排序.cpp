//
// Created by lwl on 2020/8/1.
//
#include <vector>
#include <iostream>

using namespace std;

void quickSort(int nums[], int l, int r);

int partition(int nums[], int l, int r);

void quickSort(int nums[], int n) {
    quickSort(nums, 0, n-1);
}

void quickSort(int nums[], int l, int r) {
    if (l < r) {
        int pivotLoc = partition(nums, l, r);
        quickSort(nums, l, pivotLoc - 1);
        quickSort(nums, pivotLoc + 1, r);
    }

}

int partition(int nums[], int l, int r) {
    int tmp = nums[l];
    while (l < r) {
        while (l < r && nums[r] >= tmp)
            r--;
        nums[l] = nums[r];
        while (l < r && nums[l] < tmp)
            l++;
        nums[r] = nums[l];
    }
    nums[l] = tmp;
    return l;

}

int main() {
    int nums[] = {2, 19, 7, 10, 1, 81, 100, 34};
    quickSort(nums, 8);
    for (int i = 0; i < 8; ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;
}