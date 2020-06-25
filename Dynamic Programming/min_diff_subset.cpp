//Given a set of positive numbers, partition the set into two subsets with a minimum difference between their subset sums.

#include<iostream>
#include<vector>

using namespace std;

int partition(vector<int> &nums,int index,int sum1,int sum2,vector<vector<int> > &dp){
    if(index==nums.size()){
        return abs(sum1-sum2);
    }

    if(dp[index][sum1]!=-1){
        return dp[index][sum1];
    }

    int diff1=partition(nums,index+1,sum1+nums[index],sum2,dp);
    int diff2=partition(nums,index+1,sum1,sum2+nums[index],dp);

    dp[index][sum1]=min(diff1,diff2);
    return dp[index][sum1];

    
}

int main(){
    vector<int> nums = {1, 2, 3, 100};
    int sum=0;
    for(auto val:nums){
        sum+=val;
    }

    vector<vector<int> > dp(nums.size(),vector<int>(sum+1,-1));
    cout<<partition(nums,0,0,0,dp);
}