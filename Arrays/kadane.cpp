#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
	    int n;
	    cin>>n;
	    vector<int> arr;
	    for(int j=0;j<n;j++){
	        int temp;
	        cin>>temp;
	        arr.push_back(temp);
	    }
	    
	    int sum=0,ans=INT_MIN;
	    for(int j=0;j<n;j++){
	        sum+=arr[j];
	        if(sum>ans){
	            ans=sum;
	        }
	        //cout<<sum<<" ";
	        if(sum<0){
	            sum=0;
	        }
	    }
	    if(ans==INT_MIN){
	        cout<<-1<<endl;
	    }else{
	        cout<<ans<<endl;
	    }
	}
	return 0;
}