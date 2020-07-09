#include <iostream>
#include<bits/stdc++.h>
using namespace std;


int helper(vector<int> &arr,int n,int k){
    
    sort(arr.begin(),arr.end());
    int count=0;
    int i=0;
    while(k>0){
        if(arr[i]<=k){
            k=k-arr[i];
            count++;
            i++;
        }else{
            break;
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
	    int k;
	    cin>>n>>k;
	    vector<int> arr;
	    for(int j=0;j<n;j++){
	        int temp;
	        cin>>temp;
	        arr.push_back(temp);
	    }
	    
	    cout<<helper(arr,n,k)<<endl;
	}
	return 0;
}