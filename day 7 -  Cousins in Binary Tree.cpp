/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    map<int, pair<int, int>> m;
    void dfs(TreeNode *root, int level, int no){
        if(root == NULL) return;
        m[root->val] = make_pair(level, no);
        dfs(root->left, level + 1, root->val);
        dfs(root->right, level + 1, root->val);
    }
    
    bool isCousins(TreeNode* root, int a, int b) {
        
        dfs(root, 0, -1);
        return m[a].first == m[b].first && m[a].second != m[b].second;
    }
};