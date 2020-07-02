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
	    vector<int> values;
	    for(int j=0;j<n;j++){
	        int temp;
	        cin>>temp;
	        values.push_back(temp);
	    }
	    vector<int> dp(values.begin(),values.end());
	    int maxsum=0;
	    for(int k=0;k<n;k++){
	        for(int l=0;l<k;l++){
	            if(values[k]>values[l] && dp[l]+values[k]>dp[k]){
	                dp[k]=values[k]+dp[l];
	            }
	            
	        }
	        maxsum=max(maxsum,dp[k]);
	    }
	    cout<<maxsum<<endl;
	}
	return 0;
}