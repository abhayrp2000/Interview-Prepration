
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
    
    ListNode* midpoint(ListNode *head){
        ListNode *fast=head->next,*slow=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* mergeSortedLinkedList(ListNode *a,ListNode *b){
        if(a==NULL){
            return b;
        }else if(b==NULL){
            return a;
        }
        
        ListNode *c;
        if(a->val<b->val){
            c=a;
            c->next=mergeSortedLinkedList(a->next,b);
            
        }else{
            c=b;
            c->next=mergeSortedLinkedList(a,b->next);
        }
        return c;
        
    }
    ListNode *mergeSort(ListNode *head){
        
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* mid=midpoint(head);
        ListNode *a,*b;
        a=head;
        b=mid->next;
        mid->next=NULL;
            
        a=mergeSort(a);
        b=mergeSort(b);
        
        ListNode *c=mergeSortedLinkedList(a,b);
        return c;
    }
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
};