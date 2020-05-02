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
    ListNode* partition(ListNode* head, int x) {
        ListNode *b_head=new ListNode(-1);
        ListNode *a_head=new ListNode(-1);
        ListNode *after=a_head,*before=b_head;
        
        while(head){
            if(head->val<x){
                before->next=head;
                before=before->next;
                
            }else{
                after->next=head;
                after=after->next;
            }
            head=head->next;
            
        }
        
        after->next=NULL;
        before->next=a_head->next;
        
        return b_head->next;
    }
};