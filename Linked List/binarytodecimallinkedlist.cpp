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
    int getDecimalValue(ListNode* head) {
        
        string s;
        while(head!=NULL){
            s+=head->val+'0';
            head=head->next;
        }
        
        int n=s.size();
        
        int result=0;
        for(int i=0;i<n;i++){
            cout<<i<<endl;
            result+=((s[i]-'0')*pow(2,(n-i-1)));
        }
        return result;
        
    }
};