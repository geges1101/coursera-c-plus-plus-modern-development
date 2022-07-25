#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
    if (x < 0) {
        return false;
    }
    auto s = to_string(x);

    for (auto i = 0; i != s.size() / 2; i++) {
        if(s[i] != s[s.size() - 1 - i]){
            return false;
        }
    }
    return true;
}
};


