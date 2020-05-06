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
    pair<int,bool> check(TreeNode *root){
        pair<int,bool> p;
        if(root==NULL){
            p.first=0;
            p.second=true;
            return p;
        }
        
        pair<int,bool> lefts=check(root->left);
        pair<int,bool> rights=check(root->right);
        
        p.first=max(lefts.first,rights.first)+1;
        if(abs(lefts.first-rights.first)<=1 && lefts.second && rights.second){
            p.second=true;
        }else{
            p.second=false;
        }
        return p;
    }
    bool isBalanced(TreeNode* root) {
        return(check(root).second);
    }
};