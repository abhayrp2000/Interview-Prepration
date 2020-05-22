// Problem https://leetcode.com/problems/coin-change/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        vector<int> dp(amount+1,0);
        int cS=coins.size();
        
        for(int n=1;n<=amount;n++){
            dp[n]=amount+1;
            for(int i=0;i<coins.size();i++){
                if(n-coins[i]>=0){
                    int sub=dp[n-coins[i]];
                    dp[n]=min(dp[n],sub+1);
                }
            }
        }
        if(dp[amount]>amount){
            return -1;
        }
        return dp[amount];
        
    }
};