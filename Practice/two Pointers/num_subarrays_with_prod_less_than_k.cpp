class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        if(k<=1){
            return 0;
        }
        
        int prod=1;
        int ans=0;
        int start=0;
        for(int end=0;end<nums.size();end++){
            prod=prod*nums[end];
            while(prod>=k){
                prod=prod/nums[start];
                start++;
            }
            ans=ans+(end-start+1);
        }
        
        return ans;
    }
};