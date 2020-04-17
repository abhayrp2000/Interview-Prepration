class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        int m=nums.size();
        while(i<m-1){
            if(nums[i]==nums[i+1]){
                nums.erase(nums.begin()+i);
                m=nums.size();
            }else{
                i++;
            }
        }
        
        return nums.size();
        
    }
};