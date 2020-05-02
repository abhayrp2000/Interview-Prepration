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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *prev=new ListNode(-1);
        ListNode *temp=prev;
        
        prev->next=head;
        while(head && head->next){
            if(head->next && head->val==head->next->val){
                while(head->next && head->next->val==head->val){
                    head=head->next;
                }
                prev->next=head->next;
                head=prev->next;
            }else{
                prev=prev->next;
                head=head->next;
            }
        }
        
        return temp->next;
        
    }
};