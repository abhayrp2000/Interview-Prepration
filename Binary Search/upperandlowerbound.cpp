#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> v;

    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        v.push_back(temp);
    }
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int val;
        cin>>val;

        int lb=lower_bound(v.begin(),v.end(),val)-v.begin();
        int ub=upper_bound(v.begin(),v.end(),val)-v.begin();

        if(lb==n ||ub==n){
            cout<<-1<<" "<<-1<<endl;
        }else{
            cout<<lb<<" "<<ub-1<<endl;
        }
        
    }
}