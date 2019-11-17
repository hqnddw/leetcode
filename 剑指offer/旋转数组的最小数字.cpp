//
// Created by hqnddw on 2019/11/11.
//
#include <vector>

using namespace std;

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int lo = 0;
        int hi = rotateArray.size() - 1;
        int mid = lo;
        while (rotateArray[lo] >= rotateArray[hi]) {
            if (hi - lo == 1) {
                mid = hi;
                break;
            }
            mid = lo + (hi - lo) / 2;
            if (rotateArray[mid] >= rotateArray[lo])
                lo = mid;
            if (rotateArray[mid] <= rotateArray[lo])
                hi = mid;
        }
        return rotateArray[mid];
    }
};