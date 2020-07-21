class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int last=nums.size()-1;
        int i;
        for(i=nums.size()-1;i>=0;i--){
            if(i+nums[i]>=last){
                last=i;
            }
        }
        
        if(last==0){
            return true;
        }
        
        return false;
        
    }
};