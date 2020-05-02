/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(head==NULL ||head->next==NULL){
            return head;
        }
        if(k==0){
            return head;
        }
        
        ListNode *temp=head;
        int count=0;
        while(temp){
            count++;
            temp=temp->next;
        }
        
        ListNode *last;
        
        if(k>=count){
            k=k%count;
        }
        
        if(k==0){
            return head;
        }
        
        
        int val=count-k;
        
        
        temp=head;
        int i=1;
        while(temp && i<val){
            temp=temp->next;
            i++;
        }
        
        ListNode *kthnode=temp;
        if(kthnode==NULL){
            return head;
        }
        
        while(temp->next!=NULL){
            temp=temp->next;
        }
        last=temp;
        
       
        last->next=head;
        
        head=kthnode->next;
        kthnode->next=NULL;
        
        return head;
        
        
        
                
    }
};