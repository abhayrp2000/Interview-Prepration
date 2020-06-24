#include<iostream>
#include<vector>

using namespace std;



int rod_cutting(vector<int> &lengths,vector<int> &prices,int length,int index,vector<vector<int>> &dp){
    if(length<=0 || index>=lengths.size()){
        return 0;
    }

    if(dp[index][length]!=-1){
        return dp[index][length];
    }

    int profit1=0;
    if(lengths[index]<=length){
        profit1=prices[index]+rod_cutting(lengths,prices,length-lengths[index],index,dp);
    }

    int profit2=rod_cutting(lengths,prices,length,index+1,dp);

    dp[index][length]=max(profit1,profit2);
    return dp[index][length];
    
}

int main(){
    vector<int> lengths = {1, 2, 3, 4, 5};
    vector<int> prices = {2, 6, 7, 10, 13};

    int length=5;

    vector<vector<int> > dp(lengths.size(),vector<int> (length+1,-1));
    cout<<rod_cutting(lengths,prices,length,0,dp);
}