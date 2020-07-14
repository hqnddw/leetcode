//
// Created by hqnddw on 2019/11/12.
//

#include <cmath>
#include <vector>

using namespace std;

//贪婪
class Solution1 {
public:
    int cutRope(int number) {
        if (number < 2)
            return 0;
        if (number == 2)
            return 1;
        if (number == 3)
            return 2;

        int countOf3 = number / 3;
        if (number - countOf3 * 3 == 1)
            countOf3 -= 1;
        int countOf2 = (number - countOf3 * 3) / 2;
        return (int) pow(3, countOf3) * (int) pow(2, countOf2);
    }
};


//dp动态规划
class Solution2 {
public:
    int cutRope(int number) {
        if (number < 2)
            return 0;
        if (number == 2)
            return 1;
        if (number == 3)
            return 2;
        vector<int> v(number + 1, 0);
        v[1] = 1;
        v[2] = 2;
        v[3] = 3;
        for (int i = 4; i <= number; ++i) {
            int maximum = 0;
            for (int j = 1; j <= i / 2; ++j) {
                int product = v[j] * v[i - j];
                v[i] = max(maximum, product);
            }
        }
        return v[number];
    }
};