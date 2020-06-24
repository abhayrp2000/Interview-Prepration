class Solution {
public:
    //Brite force Recursive O(2^n)//TLE 
    void helper(vector<int> &nums,int total,int curr,int index,bool &result){
        if(index>=nums.size()){
            return;
        }
        
        if(total-curr==curr){
            result=true;
            return;
        }
        
        helper(nums,total,curr+nums[index],index+1,result);
        helper(nums,total,curr,index+1,result);
    }
    bool canPartition(vector<int>& nums) {
        bool result=false;
        int sum=0;
        for(auto val:nums){
            sum+=val;
        }
        helper(nums,sum,0,0,result);
        return result;
    }
};