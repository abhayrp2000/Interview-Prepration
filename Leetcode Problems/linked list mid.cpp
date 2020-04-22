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
    ListNode* middleNode(ListNode* head) {
        
        ListNode* fast=head;
        ListNode* slow=head;
        
        if(head!=NULL){
            while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
            }
        }
        
        return slow;
        
    }
};