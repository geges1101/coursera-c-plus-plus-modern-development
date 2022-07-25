#include <iostream>
#include <vector>

using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };


class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return parser(preorder, inorder, 0, 0, inorder.size() - 1);
    }

    TreeNode* parser(vector<int>& preorder, vector<int>& inorder, int pre_begin, int in_begin, int in_end){
        if(in_begin > in_end || pre_begin > preorder.size() - 1) return nullptr;

        TreeNode* root = new TreeNode (preorder[pre_begin]);

        int idx = 0;

        for(int i = in_begin; i <= in_end; i++){
            if(root->val == inorder[i]){
                idx = i;
            }
        }

        root->left = parser(preorder, inorder, pre_begin + 1, in_begin, idx - 1);
        root->right = parser(preorder, inorder, pre_begin + idx - in_begin + 1, idx + 1, in_end);

        return root;
    }
};

