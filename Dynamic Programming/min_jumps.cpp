#include<iostream>
#include<vector>
#include<climits>

using namespace std;



int main(){
     
    vector<int> jumps = {2, 1, 1, 1, 4};
    vector<int> dp(jumps.size());
    dp[0]=0;

    for(int i=1;i<jumps.size();i++){
        dp[i]=INT_MAX;
    }

    for(int s=0;s<jumps.size();s++){
        for(int e=s+1;e<=s+jumps[s] && e<jumps.size();e++){
            dp[e]=min(dp[e],dp[s]+1);
        }
    }

    cout<<dp[jumps.size()-1];


}