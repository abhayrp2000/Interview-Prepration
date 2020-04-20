class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        vector<int> a;
        int n=nums.size();
        a.push_back(1);
        for(int i=1;i<nums.size();i++){
            a.push_back(a[i-1]*nums[i-1]);
        }
        
        int suffix=1;
        for(int i=n-2;i>=0;i--){
            suffix=suffix*nums[i+1];
            a[i]=a[i]*suffix;
            
        }
        return a;
    }
};