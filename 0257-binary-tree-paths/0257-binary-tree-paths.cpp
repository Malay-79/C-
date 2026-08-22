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
    void paths(TreeNode* root,string path,vector<string> &ans){
        if(!root) return;
        path = path + to_string(root->val);
        if(!root->left && !root->right){
            ans.push_back(path);
            return;
        }
        path += "->";
        paths(root->left,path,ans);
        paths(root->right,path,ans);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if(root==NULL) return ans;
        paths(root,"",ans);
        return ans;
    }
};