//
// Created by hqnddw on 2020/9/4.
//
#include <vector>
#include <iostream>

using namespace std;

class Finder {
public:
    int findKth(vector<int> a, int n, int K) {
        // write code here
        return quicksort(a, 0, n - 1, K);
    }

    int quicksort(vector<int> &a, int l, int r, int k) {
        int i = l, j = r;
        int tmp = a[l];
        while (i < j) {
            while (i < j && a[j] >= tmp)
                j--;
            a[i] = a[j];
            while (i < j && a[i] < tmp)
                i++;
            a[j] = a[i];
        }
        a[i] = tmp;

        int num = r - i;
        if (k - num - 1 == 0)
            return tmp;
        else if (k - num - 1 > 0)
            return quicksort(a, l, i - 1, k - num - 1);
        else return quicksort(a, i + 1, r, k);
    }
};

int main() {
    vector<int> a{1, 3, 5, 2, 2};
    Finder f;
    cout << f.findKth(a, a.size(), 2) << endl;
}