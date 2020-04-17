class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        map<int,int> mp;
        vector<int> v;
        //map<int,int>:: iterator it;
        
        for(int i=0;i<nums.size();i++){
            //int comp=target-nums[i];
            auto it=mp.find(target-nums[i]);
            if(it!=mp.end()){
                v.push_back(it->second);
                v.push_back(i);
                return v;
            }else{
                mp.insert({nums[i],i});
            }
        }
        return v;
        
        
        
        
        
    }
};