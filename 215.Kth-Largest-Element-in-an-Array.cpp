//
// Created by lwl on 2020/7/28.
//
#include <vector>
#include <queue>
#include <iostream>
#include <ctime>

using namespace std;

class Solution1 {
public:
    int findKthLargest(vector<int> &nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i : nums) {
            if (pq.size() < k)
                pq.push(i);
            else {
                pq.push(i);
                pq.pop();
            }
        }
        return pq.top();
    }
};

class Solution2 {
public:
    int findKthLargest(vector<int> &nums, int k) {
        k = nums.size() - k;
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int pivot = partition(nums, l, r);
            if (pivot == k)
                break;
            else if (pivot > k)
                r = pivot - 1;
            else l = pivot + 1;
        }
        return nums[k];
    }

    int partition(vector<int> &nums, int l, int r) {
        srand((unsigned) time(nullptr));
        swap(nums[l], nums[rand() % (r - l + 1) + l]);
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
};


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        build_heap(nums, n);
        for (int i = n - 1; i > k; --i) {
            swap(nums[i], nums[0]);
            heapify(nums, i, 0);
        }
        return nums[0];
    }
    void heapify(vector<int>& nums, int n, int i) {
        if (i >= n) return;
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int max = i;
        if (l < n && nums[l] > nums[max])
            max = l;
        if (r < n && nums[r] > nums[max])
            max = r;
        if (max != i) {
            swap(nums[i], nums[max]);
            heapify(nums, n, max);
        }
    }

    void build_heap(vector<int>& nums, int n) {
        int i = (n - 2) / 2;
        for (int j = i; j >= 0; --j) {
            heapify(nums, n, j);
        }
    }

    void heap_sort(vector<int>& nums, int n) {
        build_heap(nums, n);
        for (int i = n - 1; i >= 0; --i) {
            swap(nums[i], nums[0]);
            heapify(nums, i, 0);
        }
    }

};

int main() {
    vector<int> v{3, 2, 1, 5, 6, 4};
    Solution s;
    cout << s.findKthLargest(v, 2) << endl;
    return 0;
}