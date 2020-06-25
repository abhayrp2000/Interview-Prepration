//https://leetcode.com/problems/partition-equal-subset-sum/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        
        int sum=0;
        for(auto val:nums){
            sum+=val;
        }
        
        if(sum%2!=0){
            return false;
        }
        
        sum=sum/2;
        
        int n=nums.size();
        vector<vector<bool> > dp(n,vector<bool> (sum+1,false));
        
        for(int i=0;i<n;i++){
            dp[i][0]=true;
        }
        
        for(int s=1;s<=sum;s++){
            if(nums[0]==s){
                dp[0][s]=true;
            }
        }
        
        for(int i=1;i<n;i++){
            for(int s=1;s<=sum;s++){
                if(dp[i-1][s]){
                    dp[i][s]=dp[i-1][s];
                }else if(s>=nums[i]){
                    dp[i][s]=dp[i-1][s-nums[i]];
                }
            }
        }
        
        return dp[n-1][sum];
        
    }
};