class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        sort(nums.begin(),nums.end());
        int diff=INT_MAX;
        
        for(int i=0;i<nums.size()-1;i++){
            int s=i+1;
            int e=nums.size()-1;
            while(s<e){
                int sum=nums[i]+nums[s]+nums[e];
                if(abs(target-sum)<abs(diff)){
                    diff=target-sum;
                }
                
                if(sum<target){
                    s++;
                }else{
                    e--;
                }
            }
            
            
        }
        return target-diff;
        
        
    }
};