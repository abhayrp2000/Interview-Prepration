class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        vector<vector<int> > res;
        if(intervals.size()==0){
            res.push_back(newInterval);
            return res;
        }
        
        int i;
        for(i=0;i<intervals.size();i++){
            if(newInterval[0]<=intervals[i][0]){
                intervals.insert(intervals.begin()+i,newInterval);
                break;
            }
        }
        
        if(i==intervals.size()){
            intervals.push_back(newInterval);
        }
        
        
        
         
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