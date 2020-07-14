//
// Created by hqnddw on 2019/11/7.
//
#include <string>
#include <cstring>

class Solution {
public:
    void replaceSpace(char *str, int length) {
        int countSpace = 0;
        int originLength = 0;
        int i = 0;
        while (str[i] != '\0') {
            ++originLength;
            if (str[i] == ' ')
                countSpace++;
            ++i;
        }
        int newLength = originLength + countSpace * 2;
        int index1 = originLength;
        int index2 = newLength;
        while (index1 >= 0 && index2 > index1) {
            if (str[index1] == ' ') {
                str[index2--] = '0';
                str[index2--] = '2';
                str[index2--] = '%';
            } else str[index2--] = str[index1];
            index1--;
        }
    }
};