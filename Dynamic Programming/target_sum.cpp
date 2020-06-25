//Given a set of positive numbers (non zero) and a target sum ‘S’. Each number should be assigned either a ‘+’ or ‘-’ sign. We need to find out total ways to assign symbols to make the sum of numbers equal to target ‘S’.


//problem reduces to count subsets which add up to (target+(sum(numbers)))/2
#include<iostream>
#include<vector>
using namespace std;

int target_sum(vector<int> nums,int index,int sum,vector<vector<int>> &dp){
    if(sum==0){
        return 1;
    }
    if(index>=nums.size()){
        return 0;
    }

    if(dp[index][sum]!=-1){
        return dp[index][sum];
    }

    int op1=0;
    if(sum>=nums[index]){
        op1=target_sum(nums,index+1,sum-nums[index],dp);
    }
    int op2=target_sum(nums,index+1,sum,dp);
    dp[index][sum]=op1+op2;
    return dp[index][sum];
}

int main(){
    vector<int> num = {1, 2, 7, 1};
    int target=9;
    
    int sum=0;
    for(auto val:num){
        sum+=val;
    }

    sum=target+sum;
    sum=sum/2;

    vector<vector<int> > dp(num.size(),vector<int> (sum+1,-1));
    cout<<target_sum(num,0,sum,dp);

}