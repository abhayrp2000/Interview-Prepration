#include <iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
	    int n,m;
	    cin>>n>>m;
	    string s1,s2;
	    cin>>s1>>s2;
	    vector<vector<int> > dp(n+1,vector<int> (m+1,0));
	    int maxlength=0;
	    for(int i=1;i<=n;i++){
	        for(int j=1;j<=m;j++){
	            if(s1[i-1]==s2[j-1]){
	                dp[i][j]=1+dp[i-1][j-1];
	                maxlength=max(maxlength,dp[i][j]);
	            }
	            
	        }
	        
	    }
	    cout<<maxlength<<endl;
	}
	return 0;
}