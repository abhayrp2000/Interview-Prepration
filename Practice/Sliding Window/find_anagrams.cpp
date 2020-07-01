class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        vector<int> result;
        
        int n=s.size();
        
        map<char,int> mp;
        
        for(auto val:p){
            mp[val]++;
        }
        
        int match=0;
        int start=0;
        
        for(int end=0;end<n;end++){
            char temp=s[end];
            if(mp.find(temp)!=mp.end()){
                mp[temp]--;
                if(mp[temp]==0){
                    match++;
                }
            }
            
            if(match==(int)mp.size()){
                result.push_back(start);
            }
            
            if(end>=p.size()-1){
                temp=s[start];
                if(mp.find(temp)!=mp.end()){
                    if(mp[temp]==0){
                        match--;
                    }
                    mp[temp]++;
                    
                }
                start++;
            }
            
            

            
        }
        
        return result;
        
    }
};