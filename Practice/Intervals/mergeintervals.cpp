class Solution {
public:
    
    static bool comp(vector<int> &a,vector<int> &b){
        return a[0]<b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        if(intervals.size()<=1){
            return intervals;
        }
        
        sort(intervals.begin(),intervals.end(),comp);
        
        vector<vector<int> > res;
        res.push_back(intervals[0]);
        
        for(int i=1;i<intervals.size();i++){
            int n=res.size();
            if(res[n-1][1]>=intervals[i][0]){
                vector<int> v{res[n-1][0],max(res[n-1][1],intervals[i][1])};
                res.pop_back();
                res.push_back(v);
            }else{
                res.push_back(intervals[i]);
            }
        }
        
        return res;
        
    }
};