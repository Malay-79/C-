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
    bool isvalidbst(TreeNode* root,long minval,long maxval){
        if(root==NULL) return true;

        if(root->val >= maxval || root->val <= minval) return false;

        return isvalidbst(root->left,minval,root->val) && isvalidbst(root->right,root->val,maxval);
    } 
    bool isValidBST(TreeNode* root) {
        return isvalidbst(root,LONG_MIN , LONG_MAX);
        
    }
};