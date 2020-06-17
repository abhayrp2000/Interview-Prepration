#include <iostream>
#include<vector>
#include<map>
using namespace std;

string check(vector<int> &v){
    int sum=0;
    map<int,int> mp;
    for(int i=0;i<v.size();i++){
        sum+=v[i];
        if(mp.find(sum)!=mp.end() || sum==0){
            return "Yes";
        }else{
           mp[sum]=1; 
        }
        
    }

    return "No";
}

int main() {
	//code
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
	    int n;
	    cin>>n;
	    vector<int> v;
	    for(int j=0;j<n;j++){
	        int temp;
	        cin>>temp;
	        v.push_back(temp);
	    }
	    cout<<check(v)<<endl;
	}
	return 0;
}