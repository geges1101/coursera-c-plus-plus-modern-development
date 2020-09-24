class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        queue<TreeNode*> q;
        int depth = 1;

        if (root)
            q.push(root);

        if (d == 1) {
            auto tmp = new TreeNode(v);
            tmp->left = root;
            return tmp;
        }

        while (!q.empty()) {
            auto size = q.size();
            for (auto i = 0 ; i < size; i++) {
                auto n = q.front();
                q.pop();
                if (depth == d - 1) {
                    auto r = new TreeNode(v);
                    auto l = new TreeNode(v);
                    r->right = n->right;
                    l->left = n->left;
                    n->left = l;
                    n->right = r;
                }
                if (n->left)
                    q.push(n->left);
                if (n->right)
                    q.push(n->right);
            }
            depth++;
        }
        return root;
    }
};
