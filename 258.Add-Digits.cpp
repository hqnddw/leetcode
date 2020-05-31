//
// Created by yida on 2020/5/23.
//

class Solution {
public:
    int addDigits(int num) {

        while (num >= 10) {
            int sum = 0;
            while (num) {
                sum += num % 10;
                num /= 10;
            }
            num = sum;
        }
        return num;
    }
};