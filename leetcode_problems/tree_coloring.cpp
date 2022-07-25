#include <vector>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int left, right, val;
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        val = x, n = count(root);
        return max(max(left, right), n - left - right - 1) > n / 2;
    }

    int count(TreeNode* node) {
        if (!node) return 0;
        int l = count(node->left), r = count(node->right);
        if (node->val == val)
            left = l, right = r;
        return l + r + 1;
    }


};