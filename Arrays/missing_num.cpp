#include <iostream>
#include<vector>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	
	for(int i=0;i<t;i++){
	    int n;
	    cin>>n;
	    
	    vector<int> v;
	    for(int i=1;i<n;i++){
	        int temp;
	        cin>>temp;
	        v.push_back(temp);
	    }
	    
	    int actual_sum=0;
	    for(auto val:v){
	        actual_sum+=val;
	    }
	    
	    int expected=(n*(n+1))/2;
	    cout<<expected-actual_sum<<endl;
	}
	return 0;
}