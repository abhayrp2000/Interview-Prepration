#include <iostream>
#include<vector>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
	    int n;
	    cin>>n;
	    if(n<=1){
	        cout<<1<<endl;
	    }else{
	        vector<int> dp(n+1);
    	    dp[0]=1;
    	    dp[1]=1;
    	    dp[2]=2;
    	    for(int j=3;j<=n;j++){
    	        dp[j]=dp[j-1]+dp[j-2]+dp[j-3];
    	        //cout<<dp[j]<<" ";
    	    }
    	    cout<<dp[n]<<endl;
	    }
	    
	}
	return 0;
}