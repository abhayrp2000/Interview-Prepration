class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        if(n<=1){
            return s;
        }
        
        if(n==2){
            if(s[0]==s[1]){
                return s;
            }else{
                return s.substr(0,1);
            }
        }
    
        
        vector<vector<bool> > dp(n,vector<bool> (n,false));  
        
        int maxLength=1;
        
        for(int i=0;i<n;i++){
            dp[i][i]=true;
        }
        int i1=0,i2=0;
        for(int start=n-1;start>=0;start--){
            for(int end=start+1;end<n;end++){
                if(s[start]==s[end]){
                    if(end-start==true || dp[start+1][end-1]){
                        dp[start][end]=true;
                        if(end-start+1>maxLength){
                            i1=start;
                            i2=end;
                            maxLength=end-start+1;
                        }                    
                    }
                }
            }
        }
        string res;
        for(int i=i1;i<=i2;i++){
            res+=s[i];
        }
        return res;
    }
};