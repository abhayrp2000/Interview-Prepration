#include<vector>
#include<iostream>

using namespace std;

int search(vector<int> &v,int key,int n){
    int s=0;
    int e=n-1;

    while (s<=e)
    {
        int mid=(s+e)/2;
        if(v[mid]==key){
            return mid;
        }else if(v[mid]<=v[s]){
            if(key>=v[s] && key<=v[mid]){
                e=mid-1;
            }else{
                s=mid+1;
            }
        }else{
            if(key>=v[mid] && key<=v[e]){
                s=mid+1;
            }else{
                e=mid-1;
            }
        }
    }
    return -1;
    
}


int main(){
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int data;
        cin>>data;
        v.push_back(data);
    }
    int key;
    cin>>key;

    cout<<search(v,key,n);
}