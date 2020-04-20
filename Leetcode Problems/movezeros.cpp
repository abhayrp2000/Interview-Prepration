class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        for(auto x: nums){
            if(x!=0){
                nums[i]=x;
                i++;
            }
        }
        for(int j=i;j<n;j++){
            nums[j]=0;
        }
        
    }
};