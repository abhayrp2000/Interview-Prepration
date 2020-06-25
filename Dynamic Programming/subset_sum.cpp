//Given a set of positive numbers, determine if there exists a subset whose sum is equal to a given number ‘S’.

#include<iostream>
#include<vector>

using namespace std;

int main(){


    vector<int> nums = {1, 2, 3, 7};
    int sum=6;

    int n=nums.size();

    vector<vector<bool> > dp(n,vector<int> (sum+1,false));

    for(int i=0;i<n;i++){
        dp[i][0]=true;//0 sum
    }

    for(s=1;s<=sum;s++){
        if(s==nums[0]){
            dp[0][s]=true;
        }
    }

    for(int i=0;i<n;i++){
        for(int s=1;s<=sum;s++){
            if(dp[i-1][s]){
                dp[i][s]=dp[i-1][s];
            }else if(s>=nums[i]){
                dp[i][s]=dp[i-1][s-nums[i]];
            }
        }
    }

    cout<<dp[n-1][sum];
    return 0;


}