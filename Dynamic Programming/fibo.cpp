#include<iostream>
using namespace std;


int fib(int n,int dp[]){
    if(n==1 || n==0){
        dp[n]=n;
        return n;
    }
    if(dp[n]!=0){
        return dp[n];
    }
    int ans=0;
    ans=fib(n-1,dp)+fib(n-2,dp);
    dp[n]=ans;
    return ans;
}


int main(){
    int n=12;
    int dp[100]={0};
    cout<<fib(n,dp);
}