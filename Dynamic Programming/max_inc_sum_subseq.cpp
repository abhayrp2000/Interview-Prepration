#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector<int> nums = {1, 3, 8, 4, 14, 6, 14, 1, 9, 4, 13, 3, 11, 17, 29};

    int n=nums.size();

    vector<int> dp(n);
    dp[0]=nums[0];
    int maxSum=dp[0];

    for(int i=1;i<n;i++){
        dp[i]=nums[i];
        for(int j=0;j<i;j++){
            if(nums[i]>nums[j] && dp[i]<dp[j]+nums[i]){
                dp[i]=dp[j]+nums[i];
            }
        }
        maxSum=max(maxSum,dp[i]);
    }

    cout<<maxSum<<endl;
    return 0;
}