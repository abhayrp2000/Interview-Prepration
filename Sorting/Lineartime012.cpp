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


    vector<int> res;
    int l=0,m=0,e=n-1;

    while(m<=e){
        if(v[m]==0){
            swap(v[m],v[l]);
            l++;
            m++;
        }else if(v[m]==1){
            m++;
        }else{
            swap(v[e],v[m]);
            e--;
        }
    }

    for(int n:v){
        cout<<n<<endl;
    }

}