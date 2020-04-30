#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool canPlace(int mid,vector<int> &v,int n,int m){
    int cowPos=v[0];
    int cows=1;

    for(int i=1;i<n;i++){
        if(v[i]-cowPos>=mid){
            
            cows++;
            if(cows==m){
                return true;
            }
            cowPos=v[i];
        }
    }
    return false;
}

int agg_cows(vector<int> &v,int n,int c){
    int s=0;
    
    int e=v[n-1]-v[0];

    int ans=0;

    while(s<=e){
        int mid=(s+e)/2;
        if(canPlace(mid,v,n,c)){
            ans=mid;
            s=mid+1;
        }else{
            e=mid-1;
        }
    }
    return ans;
}

int main(){
    int n,c;
    cin>>n>>c;
    vector<int> v;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        v.push_back(temp);
    }
    sort(v.begin(),v.end());
    cout<<agg_cows(v,n,c)<<endl;
}