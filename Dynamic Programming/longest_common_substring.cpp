#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(){
    string s1="passport";
    string s2="psspt";

    vector<vector<int> > dp(s1.size()+1,vector<int> (s2.size()+1,0));

    int length=0;
    for(int i=1;i<s1.size();i++){
        for(int j=1;j<s2.size();j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
                length=max(length,dp[i][j]);
            }
        }
    }
    cout<<length;
}