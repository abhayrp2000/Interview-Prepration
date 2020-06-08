//https://leetcode.com/problems/unique-number-of-occurrences/
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int> mp;
        
        for(auto val:arr){
            mp[val]++;
        }
        
        map<int,int> check;
        
        for(auto val:mp){
            if(check.find(val.second)!=check.end()){
                return false;
            }else{
                check.insert(make_pair(val.second,1));
            }
        }
        
        return true;
    }
};