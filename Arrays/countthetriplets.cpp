#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int helper(int n,vector<int> &arr){
    int count=0;
    for(int i=n-1;i>=0;i--){
        int start=0;
        int end=i-1;
        while(start<end){
            if(arr[i]==arr[start]+arr[end]){
                count++;
                start++;
                end--;
            }
            else if(arr[i]>arr[start]+arr[end]){
                start++;
            }else{
                end--;
            }
        }
    }
    if(count==0){
        return -1;
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
	    vector<int> arr;
	    for(int j=0;j<n;j++){
	        int temp;
	        cin>>temp;
	        arr.push_back(temp);
	    }
	    sort(arr.begin(),arr.end());
	    cout<<helper(n,arr)<<endl;
	}
	return 0;
}