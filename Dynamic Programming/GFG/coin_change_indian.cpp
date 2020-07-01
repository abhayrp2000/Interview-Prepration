#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int deno[]={ 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};


void check(int V){
    int n=sizeof(deno)/sizeof(deno[0]);
    
    vector<int> ans; 
  
 
    for (int i = n - 1; i >= 0; i--) { 
        while (V >= deno[i]) { 
            V -= deno[i]; 
            ans.push_back(deno[i]); 
        } 
    } 
  
    for (int i = 0; i < ans.size(); i++) 
        cout << ans[i] << " "; 
    
}

int main() {
	
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
	    int temp;
	    cin>>temp;
	    check(temp);
	    cout<<endl;
	}
	return 0;
}