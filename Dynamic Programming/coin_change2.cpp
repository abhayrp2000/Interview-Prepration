#include<iostream>
#include<vector>

// COIN CHANGE
//Given an infinite supply of ‘n’ coin denominations and a total money amount, we are asked to find the total number of distinct ways to make up that amount.
using namespace std;

int count_ways(vector<int> &deno,int val,int index,vector<vector<int>> &dp){
    if(val==0){
        return 1;
    }
    if(index>=deno.size()){
        return 0;
    }

    if(dp[index][val]!=-1){
        return dp[index][val];
    }

    int sum1=0;
    if(val>=deno[index]){
        sum1=count_ways(deno,val-deno[index],index,dp);
    }
    int sum2=count_ways(deno,val,index+1,dp);
    dp[index][val]=sum1+sum2;
    return dp[index][val];
}

int main(){
    vector<int> denominations = {1, 2, 3};

    vector<vector<int> > dp(denominations.size(),vector<int> (46,-1));
    cout<<count_ways(denominations,45,0,dp);
}