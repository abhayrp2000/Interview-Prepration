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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode *dummy=new ListNode(-1);
        dummy->next=head;
        ListNode *prev=dummy;
        ListNode *curr;
        
        while(prev->next){
            curr=prev->next;
            int sum=0;
            for(;curr!=NULL;curr=curr->next){
                sum+=curr->val;
                if(sum==0){
                    prev->next=curr->next;
                    break;
                }
            }
            if(curr==NULL){
                prev=prev->next;
            }
        }
        return dummy->next;
    }
};