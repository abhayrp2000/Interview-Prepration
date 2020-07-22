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
    
    bool helper(TreeNode *root,long lower,long higher){
        if(root==NULL){
            return true;
        }
        
       
        
        if(root->val<=lower||  root->val>=higher){
            return false;
        }
        
        return helper(root->left,lower,root->val) && helper(root->right,root->val,higher);
    }
    bool isValidBST(TreeNode* root) {
        
        return helper(root,LONG_MIN,LONG_MAX);
        
       
        
    }
};