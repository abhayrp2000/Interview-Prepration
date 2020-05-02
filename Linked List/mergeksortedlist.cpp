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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        vector<int> vec;
        
        for(int i=0;i<lists.size();i++){
            ListNode *temp=lists[i];
            while(temp){
                vec.push_back(temp->val);
                temp=temp->next;
            }
        }
        
        sort(vec.begin(),vec.end());
        
        ListNode *dummy=new ListNode(-1);
        ListNode *head=dummy;
        for(auto val:vec){
            head->next=new ListNode(val);
            head=head->next;
        }
        
        return dummy->next;
        
    }
};