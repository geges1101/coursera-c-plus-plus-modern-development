#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {

        if(digits.empty()){
            return {};
        }

        unordered_map <char,string> buttons{
                {'2', "abc"},
                {'3', "def"},
                {'4', "ghi"},
                {'5', "jkl"},
                {'6', "mno"},
                {'7', "pqrs"},
                {'8', "tuv"},
                {'9', "wxyz"}
        };

        vector<string> result;
        string combo(digits.length(), ' ');

        PermuteLoop(buttons, digits, 0, result, combo);
        return result;
    }

    void PermuteLoop(unordered_map <char,string>& buttons, const string& digits, int idx, vector<string> &result, string& combo)	{
        if (idx == digits.length()) {

            result.push_back(combo);
            return;
        }

        for(auto c : buttons[digits[idx]]){
            combo[idx] = c;
            PermuteLoop(buttons,digits,idx + 1, result, combo);
    }

    }
};