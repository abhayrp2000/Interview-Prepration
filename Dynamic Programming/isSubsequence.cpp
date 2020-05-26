class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        bool res=true;
        
        int i=0,j=0;
        
        for(i=0;i<t.size();i++){
            if(t[i]==s[j]){
                j++;
            }
        }
        
        if(j!=s.size()){
            res=false;
        }
        
        return res;
        
    }
};
