#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > combos;
        vector<int> combo;
        ComboLoop(candidates, target, combos, combo, 0);
        return combos;
    }
private:
    void ComboLoop(vector<int> &candidates, int target, vector<vector<int> > &combos, vector<int> &combo, int idx) {
        if (!target) {
            combos.push_back(combo);
            return;
        }
        for (int i = idx; i != candidates.size() && target >= candidates[i]; ++i)
            if (i == idx || candidates[i] != candidates[i - 1]) {
                combo.push_back(candidates[i]);
                ComboLoop(candidates, target - candidates[i], combos, combo, i + 1);
                combo.pop_back();
            }
    }
};