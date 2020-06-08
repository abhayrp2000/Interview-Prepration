//https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        
        vector<int> v(101,0);
        
        for(auto val:nums){
            v[val]++;
        }
        vector<int> prefix(101,0);
        prefix[0]=v[0];
        for(int i=1;i<101;i++){
            prefix[i]=prefix[i-1]+v[i];
        }
        
        vector<int> result;
        
        for(auto val:nums){
            if(val==0){
                result.push_back(0);
            }else{
                 int temp=prefix[val]-v[val];
            result.push_back(temp);
            }
           
        }
        
        return result;
        
    }
};