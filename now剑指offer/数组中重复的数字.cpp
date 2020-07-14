//
// Created by hqnddw on 2019/11/10.
//
#include <vector>

using namespace std;

class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int *duplication) {
        if (length <= 0)
            return false;
        for (int i = 0; i < length; ++i) {
            if (numbers[i] < 0 || numbers[i] > length - 1)
                return false;
        }
        for (int j = 0; j < length; ++j) {
            while (numbers[j] != j) {
                if (numbers[j] == numbers[numbers[j]]) {
                    *duplication = numbers[j];
                    return true;
                }
                swap(numbers[j], numbers[numbers[j]])
            }
        }
        return false;
    }
};