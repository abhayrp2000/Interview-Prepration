#include <iostream>
#include<string>
#include<vector>
using namespace std;

int lcs(string s1,string s2,int i,int j,vector<vector<int> > &dp){
    if(i==s1.size() || j==s2.size()){
        return 0;
    }
    
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    
    if(s1[i]==s2[j]){
        dp[i][j]=1+lcs(s1,s2,i+1,j+1,dp);
        return dp[i][j];
    }
    
    int op1=lcs(s1,s2,i+1,j,dp);
    int op2=lcs(s1,s2,i,j+1,dp);
    dp[i][j]=max(op1,op2);
    return dp[i][j];
}

int main() {
	//code
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
	    int n,m;
	    cin>>n>>m;
	    string s1,s2;
	    cin>>s1>>s2;
	    vector<vector<int> > dp(n,vector<int> (m,-1));
	    cout<<lcs(s1,s2,0,0,dp);
	}
	return 0;
}