class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l=0, r = n-1;

        unordered_set<char> visited;

        int res = 0;

        for(int r=0;r<n;r++){
            if(!visited.count(s[r])){
                visited.insert(s[r]);
                res = max(res,r-l+1);

            }
            else{
                while(l!=r && s[l]!=s[r])
                    visited.erase(s[l++]);

                visited.erase(s[l++]);
                visited.insert(s[r]);

                res = max(res,r-l+1);
            }
        }

        return res;
    }
};