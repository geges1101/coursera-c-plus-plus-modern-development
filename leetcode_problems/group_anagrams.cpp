#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      vector<vector<string>> result;
      unordered_map<string,vector<string>> groups;

      for(auto s : strs){
          string combo = s;
          sort(combo.begin(), combo.end());
          groups[combo].push_back(s);
      }

      for(auto i : groups){
          result.push_back(i.second);
      }

      return result;
    }
};
