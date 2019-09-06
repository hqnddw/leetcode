//
// Created by hqnddw on 2019/9/4.
//
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;


//极慢的方法
class Solution1 {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        vector<int> nums;
        nums.resize(nums1.size() + nums2.size());
        merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), nums.begin());
        int n = nums.size();
        double re = 0;
        if (n % 2 == 0) {
            re = ((double) (nums[n / 2 - 1] + nums[n / 2])) / 2;
            return re;
        } else return nums[n / 2];
    }
};


//O(log(min(m,n)))
class Solution2 {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int l = 0, r = m;
        if (m > n)
            return findMedianSortedArrays(nums2, nums1);
        while (l <= r) {
            int i = (l + r) / 2;
            int j = (m + n + 1) / 2 - i;
            if (i < m && nums2[j - 1] > nums1[i])
                l = i + 1;
            else if (i && nums1[i - 1] > nums2[j])
                r = i - 1;
            else { // i is the value
                int max_of_left;
                if (i == 0) max_of_left = nums2[j - 1];
                else if (j == 0) max_of_left = nums1[i - 1];
                else max_of_left = max(nums1[i - 1], nums2[j - 1]);

                if ((m + n) % 2 == 1)
                    return max_of_left;
                int min_of_right;

                if (i == m) min_of_right = nums2[j];
                else if (j == n) min_of_right = nums1[i];
                else min_of_right = min(nums1[i], nums2[j]);

                return (min_of_right + max_of_left) / 2.0;
            }
        }
        return 0.0;
    }
};


//O(log(m+n)
class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int left = (m + n + 1) / 2;
        int right = (m + n + 1) / 2;
        return (getKth(nums1, 0, m - 1, nums2, 0, n - 1, left) +
                getKth(nums1, 0, m - 1, nums2, 0, n - 1, right)) * 0.5;
    }

    int getKth(vector<int> &nums1, int start1, int end1,
               vector<int> &nums2, int start2, int end2, int k) {
        int len1 = end1 - start1 + 1;
        int len2 = end2 - start2 + 1;

        if (len1 > len2) return getKth(nums2, start2, end2, nums1, start1, end1, k);
        if (len1 == 0) return nums2[start2 + k - 1];
        if (k == 1) return min(nums1[start1], nums2[start2]);

        int i = start1 + min(k / 2, len1) - 1;
        int j = start2 + min(k / 2, len2) - 1;

        if (nums1[i] > nums2[j])
            return getKth(nums1, start1, end1, nums2, j + 1, end2, k - (j - start2 + 1));
        else
            return getKth(nums1, i + 1, end1, nums2, start2, end2, k - (i - start1 + 1));

    }
};