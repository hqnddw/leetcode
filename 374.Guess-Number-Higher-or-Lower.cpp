//
// Created by hqnddw on 2019/10/23.
//

int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int lo = 1;
        int hi = n;
        while (lo <= hi) {
            int mid = lo + ((hi - lo) >> 1);
            int num = guess(mid);
            if (num == 0)
                return mid;
            else if (num == -1)
                hi = mid - 1;
            else lo = mid + 1;
        }
        return 0;
    }
};