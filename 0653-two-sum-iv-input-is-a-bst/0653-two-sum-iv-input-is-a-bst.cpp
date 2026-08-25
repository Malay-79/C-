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
class BSTIterator{
    stack<TreeNode *> st;
    //reverse->true->before
    //reverse->false->next
    bool reverse = true;
private:
    void pushall(TreeNode *node){
        while(node != NULL){
            st.push(node);
            if(reverse == false) node = node->left;
            else node = node->right;
        }
    }
public:
    BSTIterator(TreeNode *root,bool isReverse){
        reverse = isReverse;
        pushall(root);
    }

    bool hasnext(){
        return !st.empty();
    }

    int next(){
        TreeNode *tmpnode = st.top();
        st.pop();
        if(!reverse) pushall(tmpnode->right);
        else pushall(tmpnode->left);
        return tmpnode->val;
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(root == NULL) return false;

        BSTIterator l(root,false);
        BSTIterator r(root,true);

        int i = l.next();
        int j = r.next();

        while(i < j){
            if(i+j==k) return true;
            else if(i+j > k) j = r.next();
            else i = l.next();
        }
        return false;
    }
};