#include<iostream>
using namespace std;

class Node{
    public:
    int val;
    Node *left;
    Node *right;

    Node(){
        val=0;
        left=NULL;
        right=NULL;
    }

    Node(int val){
        this->val=val;
        left=NULL;
        right=NULL;
    }
};

Node *insert(Node *root,int value){
    if(root==NULL){
        return new Node(value);
    }
    if(value<=root->val){
        root->left=insert(root->left,value);
    }else{
        root->right=insert(root->right,value);
    }
}


int main(){
    
}