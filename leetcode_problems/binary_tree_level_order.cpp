

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

        unordered_set <TreeNode*> visited;
        vector<vector<int>> res;

        if(!root) return res;

        queue <TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int s = q.size();
            vector<int> level;
            while(s !=0 ){
                TreeNode* item = q.front();
                q.pop();

                if(!visited.count(item))
                    if(item->left) q.push(item->left);
                if(item->right) q.push(item->right);

                level.push_back(item->val);
                s--;
            }
            res.push_back(level);

        }
        return res;
    }
};