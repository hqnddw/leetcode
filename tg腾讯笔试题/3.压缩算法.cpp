//
// Created by lwl on 2020/7/14.
//

#include <string>
#include <iostream>

using namespace std;

string helper(string &s, int &i) {
    int n = 0;
    string res;
    for (; i < s.size(); ++i) {
        char c = s[i];
        if (c == '[') {
            res += helper(s, ++i);
        } else if (isdigit(c))
            n = n * 10 + c - '0';
        else if (c == '|') {
            string tmp = helper(s, ++i);
            while (n) {
                res += tmp;
                n--;
            }
            return res;
        } else if (c == ']')
            return res;
        else res += s[i];
    }
    return res;
}


int main() {
    string s;
    cin >> s;
    int i = 0;
    string str = helper(s, i);
    for (char c: str) {
        cout << c;
    }
}