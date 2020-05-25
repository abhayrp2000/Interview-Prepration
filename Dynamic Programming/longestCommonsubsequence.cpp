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