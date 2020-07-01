#include <iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

int solution(int n,vector<int> &dp,int i){
    if(n==0){
        return 0;
    }
    // if(dp[i]!=-1){
    //     return dp[i];
    // }
    
    int op1=1+solution(n,dp,i-1);
    int op2=INT_MAX;
    if(i%2==0){
        op2=1+solution(n,dp,i*2);
    }
    
    dp[i]=min(op1,op2);
    return dp[i];
    
}

int main() {
	//code
	int t;
	cin>>t;
    vector<int> result;
	for(int i=0;i<t;i++){
	    int val;
	    cin>>val;
	    vector<int> dp(val+1);
        cout<<solution(val,dp,0);
    }
    //     dp[0]=1;
    //     dp[1]=1;
    //     dp[2]=1;
    //     for(int i=3;i<=val;i++){
    //         dp[i]=1+min(dp[i-1],dp[i/2]);
    //     }
    //     cout<<dp[val]<<endl;
	    
	// }

    // for(auto val:result){
    //     cout<<val<<endl;
    // }
	return 0;
}