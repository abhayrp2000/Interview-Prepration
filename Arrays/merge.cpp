#include <iostream>
#include<vector>
using namespace std;


void merge(vector<int>  &v1,vector<int> &v2,int n,int m){
    vector<int> res(n+m);
    int k=0;
    int i=0,j=0;
    
    while(i<n && j<m){
        if(v1[i]<=v2[j]){
            res[k]=v1[i];
            i++;
            k++;
        }else {
            res[k]=v2[j];
            j++;
            k++;
        }
    }
    
    while(i<n){
        res[k]=v1[i];
        i++;
        k++;
    }
    
    while(j<m){
        res[k]=v2[j];
        j++;
        k++;
    }
    for(auto val:res){
        cout<<val<<" ";
    }
    cout<<endl;
    return ;
}

int main() {
	//code
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
	    int n,m;
	    cin>>n>>m;
	    vector<int> v1;
	    vector<int> v2;
	    for(int j=0;j<n;j++){
	        int temp;
	        cin>>temp;
	        v1.push_back(temp);
	    }
	    for(int i=0;i<m;i++){
	        int temp;
	        cin>>temp;
	        v2.push_back(temp);
	    }
	    merge(v1,v2,n,m);
	    
	}
	return 0;
}