#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

void radix_sort(vector<int> &nums) {
    vector<int> count(10);
    int n = nums.size();
    vector<int> res(nums.size(), 0);
    int max_value = 0;
    for (int i : nums)
        max_value = max(i, max_value);
    int max_digits = 0;
    while (max_value) {
        max_digits++;
        max_value /= 10;
    }
    for (int j = 0; j < max_digits; j++) {
        int t = pow(10, j);
        for (int i = 0; i < n; i++) {
            int num = nums[i] / t % 10;
            count[num]++;
        }
        for (int k = 1; k < count.size(); ++k) {
            count[k] += count[k - 1];
        }
        for (int l = nums.size() - 1; l >= 0; --l) {
            int num = nums[l] / t % 10;
            res[--count[num]] = nums[l];
        }
        nums = res;
        fill(count.begin(), count.end(), 0);
    }

}

void Print(vector<int> &nums) {
    for (int i :nums)
        cout << i << " ";
    cout << endl;
}

int main() {
    vector<int> nums{47, 65, 20, 66, 25, 53, 64, 69, 72, 22,
                     74, 25, 53, 15, 42, 36, 4, 69, 86, 19};

    cout << "Original Array = ";
    Print(nums);
    radix_sort(nums);
    cout << "Sorted Array = ";
    Print(nums);

    return 0;
}