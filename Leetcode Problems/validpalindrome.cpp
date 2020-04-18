class Solution {
public:
    bool isPalindrome(string s) {
        
       string res;
        for(auto c:s){
            if(isalpha(c)){
                res+=tolower(c);
            }else if(isalnum(c)){
                res+=c;
            }
        }
        s=res;
        reverse(res.begin(),res.end());
        if(res==s){
            return true;
        }else{
            return false;
        }
        
    }
};