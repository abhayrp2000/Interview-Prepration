

class heapCompare{
    public:
    bool operator()(const pair<int,int> &a,const pair<int,int> &b){
        return a.second>b.second;
    }
};

bool comp(vector<int> &a,vector<int> &b){
    return a[0]<b[0];
}


int Solution::solve(vector<vector<int> > &A) {
    
    sort(A.begin(),A.end(),comp);
    
    priority_queue<pair<int,int> ,vector<pair<int,int> > ,heapCompare> pq;
    int ans=0;
    for(auto meet  : A){
        while(!pq.empty() && meet[0]>=pq.top().second){
            pq.pop();
        }
        
        pq.push({meet[0],meet[1]});
        
        ans=max(ans,(int)pq.size());
    }
    return ans;
}
