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
    int DFS(TreeNode* root, int k, int& val, bool& found){
       if(!root || found) return 0;
       int left = DFS(root->left, k, val, found) + 1;
       int right = DFS(root->right, k - left, val, found) + 1;
       if(k == left) val = root->val, found = true;
       return left + right - 1;
    }
    
    int kthSmallest(TreeNode* root, int k) {
        int val = 0;
        bool found = false;
        DFS(root, k, val, found);
        return val;
    }
};