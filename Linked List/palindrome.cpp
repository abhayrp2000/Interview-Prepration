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
    
    ListNode *Reverse(ListNode *head){
        ListNode *prev=NULL;
        ListNode *curr=head,*n;
        
        while(curr!=NULL){
            n=curr->next;
            curr->next=prev;
            prev=curr;
            curr=n;
        }
        
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode *slow,*fast;
        slow=head;
        fast=head;
        
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        slow=Reverse(slow);
        fast=head;
        while(slow){
            if(fast->val!=slow->val){
                return false;
            }
            slow=slow->next;
            fast=fast->next;
        }
        
        return true;
        
    }
};