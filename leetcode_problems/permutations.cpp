#include <vector>
#include <set>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int> &num) {
        vector<vector<int>> result;

        PermuteLoop(num, 0, result);
        return result;
    }

    void PermuteLoop(vector<int> &num, int begin, vector<vector<int> > &result)	{
        if (begin >= num.size()) {

            result.push_back(num);
            return;
        }

        for (int i = begin; i < num.size(); i++) {
            swap(num[begin], num[i]);
            PermuteLoop(num, begin + 1, result);

            swap(num[begin], num[i]);
        }
    }
};



