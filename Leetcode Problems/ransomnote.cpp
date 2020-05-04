class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char,int> mp;
        
        for(auto val:magazine){
            mp[val]++;
        }
        
        for(auto val:ransomNote){
            if(mp.find(val)!=mp.end()){
                mp[val]--;
                if(mp[val]==0){
                    mp.erase(val);
                }
            }else{
                return false;
            }
        }
        
        return true;
    }
};