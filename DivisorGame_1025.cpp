#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    bool re[1001]={};
    bool divisorGame(int N) {
        for (int i = 0; i < 1001; ++i) {
            for (int j = 1; j < i / 2 + 1; ++j) {
                if (i % j == 0 && !re[i - j]) {
                    re[i] = true;
                    break;
                }
            }
        }
        return re[N];
    }
};

//int main(){
//    Solution s;
//    cout<<s.divisorGame(57)<<endl;
//    return 0;
//}