class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int start=0;
        
        
        int minlength=INT_MAX;
        int sum1=0;
        for(int end=0;end<nums.size();end++){
            sum1=sum1+nums[end];
            while(sum1>=s){
                minlength=min(minlength,end-start+1);
                sum1=sum1-nums[start];
                start++;
            }
        }
        if(minlength==INT_MAX){
            return 0;
        }else{
            return minlength;
        }
    }
};