class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        map<int,int> mp;
        int count=0;
        if(k<0){
            return 0;
        }
        for(auto val:nums){
            mp[val]++;
        }
        
        if(k!=0){
            for(auto val:mp){
                if(mp.find(val.first+k)!=mp.end()){
                    count++;
                }
            }
        }else{
            for(auto val:mp){
                if(val.second>1){
                    count++;
                }
            }
        }
        return count;
    }
};