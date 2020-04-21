#include<iostream>

using namespace std;

class node{
    public:
    int data;
    node *next;

    node(int d){
        data=d;
        next=NULL;
    }
};

void insertAtHead(node *&head,int n){
    node *newNode=new node(n);
    newNode->next=head;
    head=newNode;
    return;
}

void print(node *head){
    while(head!=NULL){
        cout<<head->data<<" -->";
        head=head->next;
    }
    return;
}

int length(node *head){
    int count=0;
    while (head->next!=NULL)
    {
        count++;
        head=head->next;
    }
    return count;
    
}

void insertAtTail(node *&head,int d){
    if(head==NULL){
        head=new node(d);
        return;
    }

    node *tail=head;
    while (tail->next!=NULL)
    {
        tail=tail->next;
    }
    tail->next=new node(d);
    return;
    
}

void insertAtPositionP(node*&head,int p,int d){
    if(head==NULL|| p==0){
        insertAtHead(head,p);
    }else if(length(head)<p){
        insertAtTail(head,d);
    }else{
        int jumps=1;
        node *temp=head;
        while (jumps<=p-1)
        {
            temp=temp->next;
            jumps++;   
        }

        node *n=new node(d);
        n->next=temp->next;
        temp->next=n;
        
    }
    return;
}

int main(){
    node *head=NULL;
    insertAtHead(head,4);
    insertAtHead(head,2);
    insertAtHead(head,1);

    insertAtPositionP(head,2,3);
    insertAtPositionP(head,6,5);


    

    print(head);
    
}