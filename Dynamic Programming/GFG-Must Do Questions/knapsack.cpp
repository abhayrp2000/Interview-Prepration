#include <iostream>
#include<vector>
using namespace std;

int knapsack(vector<int> &weights,vector<int> &val,int capacity,int i,vector<vector<int> > &dp){
    if(i==weights.size()){
        return 0;
    }
    
    if(dp[i][capacity]!=-1){
        return dp[i][capacity];
    }
    
    int op1=0;
    if(capacity>=weights[i]){
        op1=val[i]+knapsack(weights,val,capacity-weights[i],i+1,dp);
    }
    int op2=knapsack(weights,val,capacity,i+1,dp);
    dp[i][capacity]=max(op1,op2);
    return dp[i][capacity];
    
}

int main() {
	//code
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
	    int n;
	    int c;
	    cin>>n>>c;
	    vector<int> values;
	    vector<int> weights;
	    for(int j=0;j<n;j++){
	        int temp;
	        cin>>temp;
	        values.push_back(temp);
	    }
	    for(int j=0;j<n;j++){
	        int temp;
	        cin>>temp;
	        weights.push_back(temp);
	    }
	    
	    vector<vector<int> > dp(n,vector<int> (c+1,-1));
	    cout<<knapsack(weights,values,c,0,dp)<<endl;
	}
	return 0;
}