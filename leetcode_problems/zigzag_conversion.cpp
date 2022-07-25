#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;

        vector<string> zigzag(min(numRows, static_cast<int>(s.size())));

        int i = 0;
        bool edge = 0;

        for(auto c : s){
            zigzag[i] += c;
            if(i == 0 || i == numRows - 1) edge = !edge;
                i += edge ? 1 : -1;
        }
        string res;
        for(auto row : zigzag) res += row;
        return res;
    }
};
