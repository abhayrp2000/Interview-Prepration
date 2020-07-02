bool compare(struct val a,struct val b){
    return a.first<b.first;
}
int maxChainLen(struct val p[],int n)
{
//Your code here
    sort(p,p+n,compare);
    vector<int> dp(n,1);
    int maxlen=1;
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(p[j].second<p[i].first && dp[i]<dp[j]+1){
                dp[i]=dp[j]+1;
                
            }
        }
        maxlen=max(dp[i],maxlen);
    }
    return maxlen;
    
    

    
}