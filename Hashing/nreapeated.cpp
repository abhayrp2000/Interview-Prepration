//N-Repeated Element in Size 2N Array
//https://leetcode.com/problems/n-repeated-element-in-size-2n-array/
class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        
        map<int,int> mp;
        
        for(auto val:A){
            mp[val]++;
        }
        
        int num=floor(A.size()/2);
        for(auto val:mp){
            if(val.second>=num){
                return val.first;
            }
        }
        return -1;
        
    }
};