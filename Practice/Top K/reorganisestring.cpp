class comp{
    public:
    bool operator()(const pair<char,int> &a,const pair<char,int> &b){
        return a.second<b.second;
    }
};


class Solution {
public:
    string reorganizeString(string S) {
         map<char,int> mp;
        
        for(auto val:S){
            mp[val]++;
        }
        
        priority_queue<pair<char,int>,vector<pair<char,int>>,comp> pq;
        
        for(auto val:mp){
            pq.push(val);
        }
        
        
        pair<char,int> prev('a',-1);
        
        string res;
        while(!pq.empty()){
            auto curr=pq.top();
            res+=curr.first;
            pq.pop();
            
            if(prev.second>0){
                pq.push(prev);
            }
            
            curr.second--;
            prev=curr;
        }
        
        if(res.size()==S.size()){
            return res;
        }
        
        return "";
        
        
    }
};