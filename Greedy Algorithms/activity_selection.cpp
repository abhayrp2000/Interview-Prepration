#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool myCompare(pair<int,int> a,pair<int,int> b){
    return a.second<b.second;
}

int activity_selection(vector<pair<int,int> > &v){
    sort(v.begin(),v.end(),myCompare);

    int count=1;

    int i=0;
    for(int j=1;j<v.size();j++){
        if(v[j].first>=v[i].second){
            count++;
            i=j;
        }
    }
    return count;
}

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int m;
        cin>>m;
        vector<pair<int,int> > v;

        for(int j=0;j<m;j++){
            int a,b;
            cin>>a>>b;
            v.push_back(make_pair(a,b));

        }

        cout<<activity_selection(v)<<endl;


    }
}