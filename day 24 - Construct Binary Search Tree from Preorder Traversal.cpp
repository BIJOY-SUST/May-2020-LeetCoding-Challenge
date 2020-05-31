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
    TreeNode* segment_tree(TreeNode* root, int val){
        if(root == NULL) return new TreeNode(val);
        if(root->val > val) root->left = segment_tree(root->left, val);
        else root->right = segment_tree(root->right, val);
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = NULL;
        for(int i=0;i<preorder.size();i++)
            root = segment_tree(root, preorder[i]);
        return root;
    }
};