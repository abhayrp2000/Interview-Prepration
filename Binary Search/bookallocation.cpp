#include<iostream>
#include<vector>

using namespace std;

bool allocateBooks(int mid,vector<int> v,int n,int m){
    int students=1;
    int pages=0;

    for(int i=0;i<n;i++){
        if(pages+v[i]>mid){
            pages=v[i];
            students++;
            if(students>m){
                return false;
            }
        }else{
            pages+=v[i];
        }
        
    }
    return true;
}

int bookallocate(vector<int> &v,int n,int m){
    int s=v[n-1];
    int e=v[0];
    for(int i=1;i<n;i++){
        e+=v[i];
    }

    int ans=0;

    while(s<=e){
        int mid=(s+e)/2;
        if(allocateBooks(mid,v,n,m)){
            ans=mid;
            e=mid-1;
        }else{
            s=mid+1;
        }

    }
    return ans;
}

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n,m;
        cin>>n>>m;
        vector<int> v;
        for(int i=0;i<n;i++){
            int temp;
            cin>>temp;
            v.push_back(temp);
        }

        cout<<bookallocate(v,n,m)<<endl;
    }
}