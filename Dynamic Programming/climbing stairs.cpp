//Problem https://leetcode.com/problems/climbing-stairs/

class Solution {
public:
//     int climb(int n,vector<int> &dp){
//         if(n==0){
//             return 1;
            
//         }
//         if(dp[n]!=0){
//             return dp[n];
//         }
//         int ways=0;
//         for(int i=1;i<=2;i++){
//             if(n-i>=0){
//                 ways+=climb(n-i,dp);
//             }
//         }
        
//         dp[n]=ways;
//         return ways;
//     }//Top down
    int climbStairs(int n) {
        
        
        vector<int> dp(n+1,0);
        dp[0]=1;
        dp[1]=1;
       
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        
        
        return res;
        
    }
};