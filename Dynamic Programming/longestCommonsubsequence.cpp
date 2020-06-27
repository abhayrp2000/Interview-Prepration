//https://leetcode.com/problems/longest-common-subsequence/

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        int n=text1.size();
        int m=text2.size();
        
        vector<vector<int> > dp(n+1,vector<int> (m+1,0));
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                int ans=0;
                if(text1[i-1]==text2[j-1]){
                    ans=dp[i-1][j-1]+1;
                }else{
                    ans=max(dp[i-1][j],dp[i][j-1]);
                }
                dp[i][j]=ans;
            }
        }
        return dp[n][m];
        
    }
};

///class Solution {
public:
    
    int helper(string s1,string s2,int i,int j,vector<vector<int> > &dp){
        if(i==s1.size() ||j==s2.size()){
            return 0;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        if(s1[i]==s2[j]){
            dp[i][j]=1+helper(s1,s2,i+1,j+1,dp);
        }else{
            int op1=helper(s1,s2,i+1,j,dp);
            int op2=helper(s1,s2,i,j+1,dp);
            dp[i][j]=max(op1,op2);
        }
        return dp[i][j];
        
        
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int> > dp(text1.size(),vector<int> (text2.size(),-1));
        return helper(text1,text2,0,0,dp);
    }
};