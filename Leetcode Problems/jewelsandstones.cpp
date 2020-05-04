class Solution {
public:
    int numJewelsInStones(string J, string S) {
        
        map<char,int> mp;
        for(auto j:J){
            mp[j]++;
        }
        
        int count=0;
        for(auto s:S){
            if(mp.find(s)!=mp.end()){
                count++;
            }
        }
        
        return count;
    }
};