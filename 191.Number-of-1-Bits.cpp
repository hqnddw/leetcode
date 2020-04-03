#include <cstdint>
#include <bitset>

using namespace std;

//
// Created by hqnddw on 2019/11/7.
//
class Solution1 {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while (n) {
            n &= n - 1;
            res++;
        }
        return res;
    }
};


class Solution2 {
public:
    int hammingWeight(uint32_t n) {
        bitset<32> bit(n);
        return bit.count();
    }
};