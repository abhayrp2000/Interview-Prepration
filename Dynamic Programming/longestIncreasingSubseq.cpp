//https://leetcode.com/problems/longest-increasing-subsequence/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        if(n==0){
            return 0;
        }
        
        vector<int> dp(n,1);
        int res=dp[0];
        for(int i=0;i<n;i++){
            int ans=0;
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    ans=dp[j]+1;
                }
                dp[i]=max(dp[i],ans);
            }
            res=max(res,dp[i]);
        }
        
        
        
        return res;
        
    }
};