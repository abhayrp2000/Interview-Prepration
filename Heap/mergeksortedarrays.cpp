#include<iostream>
#include<queue>
#include<vector>
#include <bits/stdc++.h> 

using namespace std;

typedef pair<int, pair<int, int> > p; 

vector<int> sortkarrays(vector<vector<int> > &v){

    vector<int> result;

    // pair<int,pair<int,int> > p;

    priority_queue<p,vector<p>,greater<p> > pq;

    for(int i=0;i<v.size();i++){
        pq.push({v[i][0],{i,0}});
    }

    while(!pq.empty()){
        p temp=pq.top();
        pq.pop();

        result.push_back(temp.first);

        int whichArray=temp.second.first;
        int indexOfelement=temp.second.second;

        if(indexOfelement+1<v[whichArray].size()){
            pq.push({v[whichArray][indexOfelement+1],{whichArray,indexOfelement+1}});
        }

    }
    return result;

}


int main(){
    int n,k;
    cin>>n>>k;


    vector<vector<int>> v;

    for(int i=0;i<n;i++){
        vector<int> temp;
        for(int j=0;j<k;j++){
            int num;
            cin>>num;
            temp.push_back(num);

        }
        v.push_back(temp);
    }

    vector<int> res=sortkarrays(v);
    for(auto val : res){
        cout<<val<<" ";
    }
}