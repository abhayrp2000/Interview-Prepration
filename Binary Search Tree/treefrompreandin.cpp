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
    int i=0;
    
    TreeNode *build(vector<int> &pre,vector<int> &in,int s,int e){
        if(s>e){
            return NULL;
        }
        
        int index=-1;
        TreeNode *root=new TreeNode(pre[i]);
        for(int j=s;j<=e;j++){
            if(pre[i]==in[j]){
                index=j;
                break;
            }
        }
        i++;
        
        root->left=build(pre,in,s,index-1);
        root->right=build(pre,in,index+1,e);
        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty()){
            return NULL;
        }
        if(preorder.size()==1){
            return new TreeNode(preorder[0]);
        }
      
        return build(preorder,inorder,0,inorder.size()-1);
        
    }
};