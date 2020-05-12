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

int main(){

    Node *root=NULL;
    root=build();
    print(root);
    
    
}