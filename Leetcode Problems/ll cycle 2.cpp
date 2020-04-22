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
    
    ListNode* cyclePos(ListNode *fast,ListNode*slow,ListNode *head){
        slow=head;
        if(slow==fast){
            return slow;
        }
        while(fast!=NULL){
            fast=fast->next;
            slow=slow->next;
            if(fast==slow){
                return slow;
            }
        }
        return head;
    }
    ListNode *detectCycle(ListNode *head) {
        
        ListNode *slow=head,*fast=head;
        
        
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow){
                return cyclePos(fast,slow,head);
            }
        }
        return NULL;
        
        
        
    }
};