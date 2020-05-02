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
    int length(ListNode *head){
        int count=0;
        while(head){
            count++;
            head=head->next;
        }
        return count;
    }
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        
        vector<ListNode *> v;
        int count=length(root);
        //cout<<count;
        if(count<=k){
            while(root){
                ListNode *temp=root;
                v.push_back(root);
                root=root->next;
                temp->next=NULL;
            }
            
            int diff=k-count;
            while(diff){
                v.push_back(NULL);
                diff--;
            }
            return v;
        }else{
            int num=floor(count)/k;
            int check =num*k;
            if(check==count){
                int c=0;
                while(root){
                    ListNode *temp;
                    v.push_back(root);
                    while(c<num){
                        c++;
                        temp=root;
                        root=root->next;
                    }
                    temp->next=NULL;
                    c=0;
                }
            }else{
                int c=0;
                int diff=count-check;
                while(root){
                    ListNode *temp;
                    v.push_back(root);
                    while(c<num){
                        c++;
                        temp=root;
                        root=root->next;
                    }
                    if(diff>0){
                        diff--;
                        temp=root;
                        root=root->next;
                    }
                    temp->next=NULL;
                    c=0;
                }
            }
            
            
        }
        return v;
        
    }
};