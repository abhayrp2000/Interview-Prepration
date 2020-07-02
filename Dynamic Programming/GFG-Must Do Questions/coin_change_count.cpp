#include <iostream>
#include<vector>
using namespace std;

int count(vector<int> &deno,int amount,int i,vector<vector<int> > &dp){
    if(amount==0){
        return 1;
    }
    if(i==deno.size()){
        return 0;
    }
    
    if(dp[i][amount]!=-1){
        return dp[i][amount];
    }
    
    int op1=0;
    if(amount>=deno[i]){
        op1=count(deno,amount-deno[i],i,dp);
    }
    int op2=count(deno,amount,i+1,dp);
    
    dp[i][amount]=op1+op2;
    return dp[i][amount];
}

int main() {
	//code
	int t;
	cin>>t;
	
	for(int j=0;j<t;j++){
	    int n;
	cin>>n;
	
	vector<int> deno;
	for(int i=0;i<n;i++){
	    int temp;
	    cin>>temp;
	    deno.push_back(temp);
	}
	int amount;
	cin>>amount;
	
	vector<vector<int> > dp(n,vector<int>(amount+1,-1));
	cout<<count(deno,amount,0,dp)<<endl;
	}
	return 0;
}