class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> res(n, 1);
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                res[j] += res[j - 1];
            }
        }
        return res[n - 1];
    }
};

