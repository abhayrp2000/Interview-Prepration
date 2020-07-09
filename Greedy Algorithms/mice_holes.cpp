int Solution::mice(vector<int> &A, vector<int> &B) {
    
    if(A.size()!=B.size()){
        return -1;
    }
    
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    
    int ans=INT_MIN;
    
    for(int i=0;i<A.size();i++){
        int temp=abs(A[i]-B[i]);
        ans=max(ans,temp);
    }
    
    return ans;
}
