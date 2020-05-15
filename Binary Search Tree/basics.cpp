#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;

    Node(int d){
        data=d;
        left=NULL;
        right=NULL;
    }
};

Node *InsertintoBST(Node *root,int d){
    if(root==NULL){
        return new Node(d);
    }

    if(d<=root->data){
        root->left=InsertintoBST(root->left,d);
    }else{
        root->right=InsertintoBST(root->right,d);
    }

    return root;
}

Node *build(){
    int d;
    cin>>d;

    Node *root=NULL;
    while(d!=-1){
        root=InsertintoBST(root,d);
        cin>>d;
    }
    return root;
}

//bfs
void print(Node *root){
    queue<Node *> q;

    if(root==NULL){
        return;
    }
    q.push(root);

    while(!q.empty()){
        Node *temp=q.front();
        cout<<temp->data<<" ";
        q.pop();

        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }
    return;
}

bool search(Node *root,int data){
    if(root==NULL){
        return false;
    }

    if(root->data==data){
        return true;
    }

    if(data<=root->data){
        return search(root->left,data);
    }else{
        return search(root->right,data);
    }
}


Node *deleteinBST(Node *root,int key){
    if(root==NULL){
        return NULL;
    }else if(key<root->data){
        root->left=deleteinBST(root->left,key);
        return root;
    }else if(key==root->data){
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        if(root->left!=NULL && root->right==NULL){
            Node* temp=root->left;
            delete root;
            return temp;
        }
        if(root->right!=NULL && root->left==NULL){
            Node *temp=root->right;
            delete root;
            return temp;
        }

        Node *replace=root->right;
        while(replace->left!=NULL){
            replace=replace->left;
        }

        root->data=replace->data;
        root->right=deleteinBST(root->right,replace->data);
        return root;

    }else{
        root->right=deleteinBST(root->right,key);
        return root;
    }
}

int main(){

    Node *root=NULL;
    root=build();

    root=deleteinBST(root,5);
    print(root);

    if(search(root,10)){
        cout<<"present";
    }else{
        cout<<"Not present";
    }
    
    
}