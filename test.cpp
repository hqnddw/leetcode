#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int ia[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    vector<int> iv1(ia, ia + 5);
    vector<int> iv2(ia, ia + 9);
    cout << *mismatch(iv1.begin(), iv1.end(), iv2.begin()).first << endl;
    cout << *mismatch(iv1.begin(), iv1.end(), iv2.begin()).second << endl;
}