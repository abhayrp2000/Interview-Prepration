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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode *n=new ListNode(0);
        ListNode *head=n;
        
        int carry=0;
        while(l1!=NULL || l2!=NULL){
            int x=(l1!=NULL)?l1->val:0;
            int y=(l2!=NULL)?l2->val:0;
            int sum=x+y+carry;
            carry=sum/10;
            sum=sum%10;
            n->next=new ListNode(sum);
            n=n->next;
            
            if(l1!=NULL){
                l1=l1->next;
            }
            if(l2!=NULL){
                l2=l2->next;
            }
        }
        
        if(carry>0){
            n->next=new ListNode(carry);
        }
        return head->next;
    }
};