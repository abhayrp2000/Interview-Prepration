#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<string>

using namespace std;

bool myCompare(const pair<string,int> &a,const pair<string,int> &b){
    if(a.second==b.second){
        return a.first<b.first;
    }
    return a.second>b.second;
}

void printdetails(vector<pair<string ,int> > &v,int val){
    
    // auto it=v.begin();
    // while(it!=v.end()){
    //     if(it->second<val){
    //         v.erase(it);
    //     }
    //     it++;
    // }

    sort(v.begin(),v.end(),myCompare);

    for(auto n:v){
        cout<<n.first<<" "<<n.second<<endl;
    }



}



int main(){
    int val,n;
    cin>>val>>n;

    vector<pair<string,int> > v;
    for(int i=0;i<n;i++){
        string name;
        int sal;
        
        cin>>name;
        cin>>sal;
        if(sal>val){
            v.push_back(make_pair(name,sal));
        }
        
        

       
    }

    printdetails(v,val);
    return 0;
}