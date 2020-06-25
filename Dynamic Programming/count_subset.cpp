//Given a set of positive numbers, find the total number of subsets whose sum is equal to a given number ‘S’.

#include<iostream>
#include<vector>

using namespace std;

int count_subset(vector<int> nums,int sum,int index,vector<vector<int> > &dp){
    if(sum==0){
        return 1;
    }

    if(index>=nums.size()){
        return 0;
    }

    if(dp[index][sum]!=-1){
        return dp[index][sum];
    }

    int sum1=0;
    if(sum>=nums[index]){
        sum1=count_subset(nums,sum-nums[index],index+1,dp);
    }
    int sum2=count_subset(nums,sum,index+1,dp);

    dp[index][sum]=sum1+sum2;
    return dp[index][sum];



}

int main(){
    vector<int> nums = {1, 2, 7, 1, 5};
    int n=nums.size();
    int sum=9;

    vector<vector<int> > dp(n,vector<int> (sum+1,-1));

    cout<<count_subset(nums,sum,0,dp);
}