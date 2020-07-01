#include <iostream>
#include<vector>
#include<climits>
using namespace std;


///You are given a number N. You have to find the number of operations required to reach N from 0. You have 2 operations available:

// Double the number
// Add one to the number
int main() {
	//code
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
	    int n;
	    cin>>n;
	    vector<int> dp(n+1);
	    dp[0]=1;
	    dp[1]=1;
	    dp[2]=2;
	    
	    for(int j=3;j<=n;j++){
	        int op1=dp[j-1];
	        int op2=INT_MAX;
	        if(j%2==0){
	            op2=dp[j/2];
	        }
	        dp[j]=1+min(op1,op2);
	    }
	    cout<<dp[n]<<endl;
	}
	return 0;
}