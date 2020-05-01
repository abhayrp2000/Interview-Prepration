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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> v;
        
        while(head){
            ListNode *temp=head->next;
            bool flag=0;
            while(temp){
                if(temp->val>head->val){
                    v.push_back(temp->val);
                    flag=1;
                    break;
                }
                temp=temp->next;
            }
            if(flag==0){
                v.push_back(0);
            }
            head=head->next;
        }
        //v.push_back(0);
        
        return v;
    }
};