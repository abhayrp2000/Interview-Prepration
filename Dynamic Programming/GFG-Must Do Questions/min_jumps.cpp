#include <iostream>
#include<climits>
#include<vector>
using namespace std;


int helper(int arr[],int i,int n,vector<int> &dp){
    if(i==n-1){
        return 0;
    }
    
    if(arr[i]==0){
        return INT_MAX;
    }
    
    if(dp[i]!=-1){
        return dp[i];
    }
    
    int ans=INT_MAX;
    int k=i+1;
    int end=i+arr[i];
    
    while(k<=end &&  k<n){
        int op1=helper(arr,k++,n,dp);
        if(op1!=INT_MAX){
            ans=min(ans,1+op1);
        }
       
    }
    
    dp[i]=ans;
    return dp[i];
}

int main() {
	//code
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    
	    vector<int> dp(n,-1);
	    
	    int ans=helper(arr,0,n,dp);
	    if(ans==INT_MAX){
	        cout<<-1<<endl;
	    }else{
	        cout<<ans<<endl;
	    }
	}
	return 0;
}