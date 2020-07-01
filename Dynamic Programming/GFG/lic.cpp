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
	    vector<int> arr;
	    for(int j=0;j<n;j++){
	        int temp;
	        cin>>temp;
	        arr.push_back(temp);
	    }
	    vector<int> dp(n,1);
	    int maxlen=0;
	    for(int j=1;j<n;j++){
	        for(int k=0;k<j;k++){
	            if(arr[j]>arr[k] &&  dp[j]<dp[k]+1){
	                dp[j]=dp[k]+1;
	            }
	        }
	        maxlen=max(maxlen,dp[j]);
	    }
	    cout<<maxlen<<endl;
	    
	}
	return 0;
}