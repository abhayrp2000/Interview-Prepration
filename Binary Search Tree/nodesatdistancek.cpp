#include "BST.h"
#include<queue>
#include<string>
string findKNodes(Node* root, int k) {
    queue<Node *> q;

    int c=0;
    if(root==NULL){
        return " ";
    }

    string res="";

    while(c<k && !q.empty()){
        Node *temp=q.front();
        q.pop();
        c++;
        if(temp->leftChild){
            q.push(temp->leftChild);
        }
        if(temp->rightChild){
            q.push(temp->rightChild);
        }

    }

    while(!q.empty()){
        Node *temp=q.front();
        res+=to_string(temp->value);
        q.pop();
    }
    return res;

   
}