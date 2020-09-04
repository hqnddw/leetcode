//
// Created by lwl on 2020/8/16.
//
#include <iostream>
#include <string>
#include <cstring>
#include <stack>
#include <algorithm>

using namespace std;

/**
 * 问题简要描述：
 * 给出一个长整数以及要去掉的位数，保证剩下的数字按顺序组合的整数值最大。
 * 输入：长整数，要去掉的位数
 * 输出：处理之后的最大值
 */

int main() {
    string num;
    cin >> num;
    int m;
    cin >> m;
    stack<char> s;
    int n = num.size() - m;
    for (int i = 0; i < num.size(); ++i) {
        if (s.empty()) {
            s.push(num[i]);
        } else {
            while (!s.empty() && m > 0 && num[i] > s.top()) {
                s.pop();
                m--;
            }
            s.push(num[i]);
            if (s.size() == n) {
                break;
            }
        }
    }
    string res;
    while (!s.empty()) {
        res += s.top();
        s.pop();
    }
    reverse(res.begin(), res.end());
    cout << res << endl;

    return 0;
}



//int main() {
//    char number[100];
//    cin >> number;
//    while (1) {
//        int m, i, j, max = 0, maxLoc = -1;
//        cin >> m;
//        if (m >= strlen(number) || m < 0) return 0;//如果要求去掉的位数不小于待处理整数或者小于零则结束；
//        for (i = 0; i < (strlen(number) - m); i++)//限定寻找最大值的范围
//        {
//            max = 0;
//            for (j = maxLoc + 1; j <= (m + i); j++)//在该区域内通过比较可找出最优数字，即该位置上的最大值；
//            {
//                if (number[j] > max) {
//                    max = number[j];
//                    maxLoc = j;//maxLoc保存最大值的位置,方便寻找下一个位置的最大值时从该位置以后开始；
//                }
//            }
//            cout << number[maxLoc];
//        }
//        cout << endl;
//    }
//    return 0;
//}
//
