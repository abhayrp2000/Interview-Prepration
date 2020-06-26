class Solution {
public:
    int help_rob(vector<int> &nums,int index,vector<int> &dp){
        if(index>=nums.size()){
            return 0;
        }
        
        if(dp[index]!=-1){
            return dp[index];
        }
        
        int op1=nums[index]+help_rob(nums,index+2,dp);
        int op2=help_rob(nums,index+1,dp);
        
        dp[index]=max(op1,op2);
        return dp[index];
        
    }
    int rob(vector<int>& nums) {
        
        int n=nums.size();
        vector<int> dp(n,-1);
        return help_rob(nums,0,dp);
        
    }
};