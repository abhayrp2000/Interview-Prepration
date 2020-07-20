class Solution {
public:
    
    void helper(vector<vector<int> > &res,vector<int> &temp,int index,int target,vector<int> &nums){
        if(target==0){
            res.push_back(temp);
            return;
        }
        
       
        
        for(int i=index;i<nums.size();i++){
            if(nums[i]>target){
                return;
            }
            temp.push_back(nums[i]);
            helper(res,temp,i,target-nums[i],nums);
            temp.pop_back();
        }
        return ;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        sort(candidates.begin(),candidates.end());
        vector<vector<int> > res;
        vector<int> temp;
        
        helper(res,temp,0,target,candidates);
        return res;
    }
};