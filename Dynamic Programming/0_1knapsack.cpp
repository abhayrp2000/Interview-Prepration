#include<iostream>
#include<vector>

using namespace std;


//Recursive solution O(2^n)
int knapsack(vector<int> & profits,vector<int> & weights,int capacity,int index){
    if(index>=weights.size() || capacity<=0){
        return 0;
    }
    int profit1=0;
    if(weights[index]<=capacity){
        profit1=profits[index]+knapsack(profits,weights,capacity-weights[index],index+1);
    }
    
    int profit2=knapsack(profits,weights,capacity,index+1);

    return max(profit1,profit2);
}

int knapsackTopdown(vector<int> & profits,vector<int> &weights,int capacity,int index,vector<vector<int> > &dp){
    if(capacity<=0 || index>=weights.size()){
        return 0;
    }

    if(dp[index][capacity]!=-1){
        return dp[index][capacity];
    }

    int profit1=0;
    if(weights[index]<=capacity){
        profit1=profits[index]+knapsackTopdown(profits,weights,capacity-weights[index],index+1,dp);
    }
    int profit2=knapsackTopdown(profits,weights,capacity,index+1,dp);

    dp[index][capacity]=max(profit1,profit2);
    return dp[index][capacity];
}

int main(){
    vector<int> profits = {1, 6, 10, 16};
    vector<int> weights = {1, 2, 3, 5};
    int capacity=7;

    vector<vector<int> > dp(profits.size(),vector<int> (capacity+1,0));
    //cout<<knapsack(profits,weights,capacity,0);
    //cout<<knapsackTopdown(profits,weights,capacity,0,dp);

    //Bottom up solution

    for(int i=0;i<=capacity;i++){
        if(weights[0]<=i){
            dp[0][i]=profits[0];
        }
    }

    for(int i=1;i<weights.size();i++){
        for(int c=1;c<=capacity;c++){
            int profit1=0;
            if(weights[i]<=c){
                profit1=profits[i]+dp[i-1][c-weights[i]];
            }
            int profit2=dp[i-1][c];
            dp[i][c]=max(profit1,profit2);
        }
    }
    cout<<dp[weights.size()-1][capacity];
    return 0;
}