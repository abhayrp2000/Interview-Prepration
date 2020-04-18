class Solution {
public:
    
    void left_rotate(vector<int> &a,int k){
        reverse(a.begin(),a.begin()+k);
        reverse(a.begin()+k,a.end());
        reverse(a.begin(),a.end());
    }
    void right_rotate(vector<int> &nums,int k){
        k=k%(nums.size());
        left_rotate(nums,nums.size()-k);
    }
    void rotate(vector<int>& nums, int k) {
        right_rotate(nums,k);
    }
};