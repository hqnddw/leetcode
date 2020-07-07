//
// Created by hqnddw on 2020/6/4.
//

#include <vector>
#include <iostream>

using namespace std;

void shell_sort(vector<int> &nums) {
    for (int k = nums.size() / 2; k > 0; k /= 2) {
        for (int i = k; i < nums.size(); ++i) {
            int tmp = nums[i];
            int j = i - k;
            while (j >= 0 && nums[j] > tmp) {
                nums[j + k] = nums[j];
                j -= k;
            }
            nums[j + k] = tmp;
        }
    }
}

int main() {
    vector<int> v{6, 8, 1, 7, 11, 55, 98, 23, 12, 10, 4, 99};
    shell_sort(v);
    for (int i : v) {
        cout << i << " ";
    }
    cout << endl;
}
