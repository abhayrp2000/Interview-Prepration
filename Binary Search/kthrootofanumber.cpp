#include<iostream>
#include<math.h>

using namespace std;

int kth_root(long long int n,int k){

    long long int s=1;
    long long int e=n;
    int x=0;

    while(s<=e){
        int mid=(s+e)/2;
        
        if(pow(mid,k)>n){
            e=mid-1;
        }else if(pow(mid,k)<=n){
            x=mid;
            s=mid+1;
        }
    }
    return x;

}
int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int k;
        long long int n;
        cin>>n>>k;
        cout<<kth_root(n,k)<<endl;
    }
}