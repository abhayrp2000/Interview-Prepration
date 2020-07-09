#include <iostream>
#include<bits/stdc++.h>
using namespace std;


int helper(vector<int> &pages,int n,int p){
    int count=0;
    map<int,int> mp;
    
    for(int i=0;i<n;i++){
        if(mp.size()==p){
            if(mp.find(pages[i])!=mp.end()){
                mp[pages[i]]=i;
                continue;
            }
            int lru=INT_MAX;
            int value;
            for(auto val:mp){
                if(val.second<lru){
                    lru=val.second;
                    value=val.first;
                }
            }
            mp.erase(value);
            mp[pages[i]]=i;
            count++;
        }else if(mp.size()<p){
            if(mp.find(pages[i])==mp.end()){
                mp[pages[i]]=i;
                count++;
            }else{
                mp[pages[i]]=i;
            }
        }
    }
    return count;
}
int main() {
	//code
	
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
	    int n;
	    cin>>n;
	    vector<int> pages;
	    for(int j=0;j<n;j++){
	        int temp;
	        cin>>temp;
	        pages.push_back(temp);
	    }
	    int p;
	    cin>>p;
	    cout<<helper(pages,n,p)<<endl;
	}
	return 0;
}