#include<iostream>
#include<string>
#include<vector>

using namespace std;

int lps(string s){
    int n=s.size();

    vector<vector<int> > dp(n,vector<int>(n,0));

    for(int i=0;i<n;i++){
        dp[i][i]=1;
    }

    for(int start=n-1;start>=0;start--){
        for(int end=start+1;end<n;end++){
            if(s[start]==s[end]){
                dp[start][end]=2+dp[start+1][end-1];
            }else{
                dp[start][end]=max(dp[start+1][end],dp[start][end-1]);
            }
        }
    }

    return dp[0][n-1];
}


int main(){

    string s="cddpd";
    int temp=lps(s);
    cout<<s.size()-temp<<endl;

}