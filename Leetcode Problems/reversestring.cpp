class Solution {
public:
    
    
    void reverseString(vector<char>& s,int left,int right){
        if(left<right){
            char temp=s[left];
            s[left]=s[right];
            s[right]=temp;
            left++;
            right--;
            reverseString(s,left,right);
        }
    }
    void reverseString(vector<char>& s) {
        
        reverseString(s,0,s.size()-1);
        
    }
};