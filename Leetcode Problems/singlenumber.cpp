class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
//         unordered_map<int,int> mp;

//         int n=nums.size();
//         for(int i=0;i<n;i++){
//             mp[nums[i]]++;
//         }
//         for(auto x : mp){
//             if(x.second==1){
//                 return x.first;
//             }
//         }
//         return -1;
        
        int ans=0;
        for(auto num:nums){
            ans=ans^num;
        }
        return ans;
        
    }
};