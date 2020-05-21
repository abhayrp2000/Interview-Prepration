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
}//Top down

//Bottom up
int fibonacci(int n){
    int dp[n+1]={0};
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}


int main(){
    int n=20;
    int dp[100]={0};
    cout<<fib(n,dp);
    cout<<endl<<fibonacci(n);
}