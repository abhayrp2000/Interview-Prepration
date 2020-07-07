/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    ListNode *reverse(ListNode *head){
        ListNode *prev=NULL;
        ListNode *curr=head,*n;
        
        while(curr){
            n=curr->next;
            curr->next=prev;
            prev=curr;
            curr=n;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        
        // stack<ListNode*> s;
        
        
        ListNode*slow=head,*fast=head;
        
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        //cout<<slow->val;
        
        ListNode *newHead=reverse(slow);
        
        ListNode *res=new ListNode(0);
        ListNode *temp=res;
       
        
        while(head && newHead){
            res->next=head;
            head=head->next;
            res=res->next;
            res->next=newHead;
            newHead=newHead->next;
            res=res->next;
        }
        res->next=NULL;
        
        head=temp->next;
        
    }
};