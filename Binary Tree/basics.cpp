#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node *left;
    node *right;

    node(int d){
        data=d;
        left=NULL;
        right=NULL;
    }
};

node* buildnode(){
    int d;
    cin>>d;

    if(d==-1){
        return NULL;
    }

    node *root=new node(d);
    root->left=buildnode();
    root->right=buildnode();

    return root; 
}

void print(node *root){
    //Preorder
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    print(root->left);
    print(root->right);
}

void printInorder(node *root){
    if(root==NULL){
        return;
    }

    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);

}

void postOrderPrint(node *root){
    if(root==NULL){
        return;
    }

    postOrderPrint(root->left);
    postOrderPrint(root->right);
    cout<<root->data<<" ";
}

int height(node *root){
    if(root==NULL){
        return 0;
    }

    int ls=height(root->left);
    int rs=height(root->right);
    return max(ls,rs)+1;
}

int count(node *root){
    if(root==NULL){
        return 0;
    }

    return 1+count(root->left)+count(root->right);
}

int sumofnode(node *root){
    if(root==NULL){
        return 0;
    }

    return root->data+sumofnode(root->left)+sumofnode(root->right);
}


int main(){
    node *root=buildnode();
    print(root);
    cout<<"Inorder "<<endl;
    printInorder(root);
    cout<<"post order"<<endl;
    postOrderPrint(root);
    cout<<endl;
    cout<<"Height "<<height(root);
    return 0;
}