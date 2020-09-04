//
// Created by lwl on 2020/8/14.
//
#include <iostream>
/**
 * 时间复杂度
 * 初始化建堆过程时间：O(n)
 *    推算过程：
 *    假设高度为k，则从倒数第二层右边的节点开始，这一层的节点都要执行子节点比较然后交换
 *    （如果顺序是对的就不用交换）；倒数第三层呢，则会选择其子节点进行比较和交换，如果没交换就可以
 *    不用再执行下去了。如果交换了，那么又要选择一支子树进行比较和交换
 *     那么总的时间计算为：s = 2^(i - 1) * (k - i)；其中 i 表示第几层，
 *     2^(i - 1) 表示该层上有多少个元素，(k - i) 表示子树上要比较的次数，
 *     如果在最差的条件下，就是比较次数后还要交换；因为这个是常数，所以提出来后可以忽略
 *     S = 2^(k-2) * 1 + 2^(k-3)*2.....+2*(k-2)+2^(0)*(k-1)
 *     ===> 因为叶子层不用交换，所以i从 k-1 开始到 1；
 *     上面等式左右乘上2，然后和原来的等式相减，就变成了：
 *      S = 2^(k - 1) + 2^(k - 2) + 2^(k - 3) ..... + 2 - (k-1)
 *      除最后一项外，就是一个等比数列了，直接用求和公式：S = { a1[ 1-(q^n) ] }  / (1-q)；
 *      S = 2^k -k -1；又因为k为完全二叉树的深度，所以 (2^k) <=  n < (2^k  -1 )，
 *      总之可以认为：k = logn （实际计算得到应该是 log(n+1) < k <= logn ）;
 *      综上所述得到：S = n - longn -1，所以时间复杂度为：O(n)
 *  更改堆元素后重建堆时间：O(nlogn)
 *      循环  n -1 次，每次都是从根节点往下循环查找，
 *      所以每一次时间是 logn，总时间：logn(n-1) = nlogn  - logn ；
 *  综上所述：堆排序的时间复杂度为：O(nlogn)
 * */
using namespace std;

void heapify(int arr[], int n, int i) {
    if (i >= n) return;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int max = i;
    if (l < n && arr[l] > arr[max])
        max = l;
    if (r < n && arr[r] > arr[max])
        max = r;
    if (max != i) {
        swap(arr[i], arr[max]);
        heapify(arr, n, max);
    }
}

void build_heap(int arr[], int n) {
    int i = (n - 2) / 2;
    for (int j = i; j >= 0; --j) {
        heapify(arr, n, j);
    }
}

void heap_sort(int arr[], int n) {
    build_heap(arr, n);
    for (int i = n - 1; i >= 0; --i) {
        swap(arr[i], arr[0]);
        heapify(arr, i, 0);
    }
}

int main() {
    int arr[]{1, 4, 2, 9, 10, 6, 3};
    heap_sort(arr, 7);
    for (int i : arr)
        cout << i << " ";
    cout << endl;
}