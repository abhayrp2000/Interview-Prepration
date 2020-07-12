class comp{
  public:
    bool operator()(pair<int,int> &a,pair<int,int> &b){
        return a.second>b.second;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        map<int,int> mp;
        
        for(auto val:nums){
            mp[val]++;
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int> >,comp> pq;
        
        for(auto val:mp){
            pq.push(val);
            if(pq.size()>k){
                pq.pop();
            }
        }
        
        vector<int> res;
        
        while(!pq.empty()){
            res.push_back(pq.top().first);
            pq.pop();
        }
        
        return res;
        
        
        
    }
};