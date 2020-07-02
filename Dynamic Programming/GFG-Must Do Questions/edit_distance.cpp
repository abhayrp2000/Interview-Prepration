#include <iostream>
#include<vector>
using namespace std;

int edit_distance(string s1,string s2,int i,int j,vector<vector<int> > &dp){
    if(i==s1.size()){
        return s2.size()-j;
    }
    if(j==s2.size()){
        return s1.size()-i;
    }
    
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    
    
    if(s1[i]==s2[j]){
        dp[i][j]=edit_distance(s1,s2,i+1,j+1,dp);
        return dp[i][j];
    }
    
    int op1=edit_distance(s1,s2,i+1,j,dp);
    int op2=edit_distance(s1,s2,i,j+1,dp);
    int op3=edit_distance(s1,s2,i+1,j+1,dp);
    
    dp[i][j]=1+min(op1,min(op2,op3));
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
	    vector<vector<int> >dp(n,vector<int> (m,-1));
	    cout<<edit_distance(s1,s2,0,0,dp)<<endl;
	}
	return 0;
}