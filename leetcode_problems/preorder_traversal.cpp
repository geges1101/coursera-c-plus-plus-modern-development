class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> tree;
        if(!root) return tree;
        stack<TreeNode*> s;
        s.push(root);
        TreeNode* node = root;
        while(!s.empty()){
            node = s.top();
            s.pop();
            tree.push_back(node->val);
            if(node-> left) s.push(node -> right);
            if(node -> right) s.push(node-> left);
        }

        return tree;
    }
};

