#include <vector>
#include <iostream>
#include <queue>
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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        unordered_map <TreeNode*, TreeNode*> tree;
        unordered_set <TreeNode*> visited;
        vector<int> result;

        traverse(root, tree, target);

        queue<TreeNode*> q;
        q.push(target);

        while(!q.empty() && K >= 0){
                int s = q.size();
                while(s > 0){
                    auto item = q.front();
                    int v = item->val;
                    q.pop();

                    visited.insert(item);
                    if(0 == K) result.push_back(v);

                    if(!visited.count(tree[item]) && tree[item]) q.push(tree[item]);
                    if(!visited.count(item->left) && item->left) q.push(item->left);
                    if(!visited.count(item->right) && item->right) q.push(item->right);

                    s--;
                }
                K--;
        }
        return result;
    }


    void traverse(TreeNode* root, unordered_map<TreeNode*, TreeNode*> tree, TreeNode* target){
        while(root != nullptr || root != target){
            if(root->left != nullptr) {
                tree[root->left] = root;
                auto new_root = root->left;
                traverse(new_root, tree,target);
            }

            if(root->left != nullptr) {
                tree[root->right] = root;
                auto new_root = root->right;
                traverse(new_root, tree,target);
            }
        }
        }
};

