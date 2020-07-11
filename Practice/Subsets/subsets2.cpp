class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        int end=0,start=0;
        vector<vector<int> > res;
        res.push_back(vector<int> ());
        for(int i=0;i<nums.size();i++){
            start=0;
            
            
            if(i>0 && nums[i]==nums[i-1]){
                start=end+1;
            }
            
            end=res.size()-1;
            
            for(int j=start;j<=end;j++){
                vector<int> temp(res[j]);
                temp.push_back(nums[i]);
                res.push_back(temp);
            }
        }
        return res;
        
    }
};