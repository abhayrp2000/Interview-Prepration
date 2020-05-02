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
        ListNode *prev=NULL,*curr=head,*n;
        
        while(curr){
            n=curr->next;
            curr->next=prev;
            prev=curr;
            curr=n;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1,s2;
        
        while(l1){
            s1.push(l1->val);
            l1=l1->next;
        }
        
        while(l2){
            s2.push(l2->val);
            l2=l2->next;
        }
        
        ListNode *head=new ListNode(-1);
        ListNode *temp=head;
        int carry=0;
        
        while(!s1.empty() ||!s2.empty()){
            int x,y;
            if(!s1.empty()){
                x=s1.top();
                s1.pop();
            }else{
                x=0;
            }
            if(!s2.empty()){
                y=s2.top();
                s2.pop();
            }else{
                y=0;
            }
            
            int sum=x+y+carry;
            carry=sum/10;
            sum=sum%10;
            head->next=new ListNode(sum);
            head=head->next;
            
        }
        
        if(carry>0){
            head->next=new ListNode(carry);
        }
        
        return Reverse(temp->next);
    }
};