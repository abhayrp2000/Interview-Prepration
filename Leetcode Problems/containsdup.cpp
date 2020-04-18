class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        map<int,int>  mp;
        
        for(int i=0;i<nums.size();i++){
            auto it=mp.find(nums[i]);
            if(it!=mp.end()){
                return true;
            }else{
                mp[nums[i]]=1;
            }
        }
        return false;
        
    }
};