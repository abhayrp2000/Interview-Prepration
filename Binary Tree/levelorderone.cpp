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
    int height(TreeNode *root){
        if(root==NULL){
            return 0;
        }
        
        int ls=height(root->left);
        int rs=height(root->right);
        
        return max(ls,rs)+1;
    }
    
    void printkthlevel(TreeNode *root,int k,vector<int> &res){
        if(root==NULL){
            return;
        }
        if(k==1){
            res.push_back(root->val);
            return;
        }
        printkthlevel(root->left,k-1,res);
        printkthlevel(root->right,k-1,res);
    }
    
    vector<vector<int>> print(TreeNode *root){
        int h=height(root);
        vector<vector<int>> p;
        for(int i=1;i<=h;i++){
            vector<int> v;
            printkthlevel(root,i,v);
            p.push_back(v);
            v.clear();
        }
        return p;
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        return print(root);
    }
};