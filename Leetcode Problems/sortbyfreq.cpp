class Solution {
public:
    static bool myCompare(pair<char,int> p1,pair<char,int> p2){
        return p1.second>p2.second;
    }
    string frequencySort(string s) {
        string res;
        map<char,int> mp;
        for(auto val:s){
            mp[val]++;
        }
        vector<pair<char,int>> v(mp.begin(),mp.end());
        sort(v.begin(),v.end(),myCompare);
        
        for(int i=0;i<v.size();i++){
            while(v[i].second--){
                res+=v[i].first;
            }
        }
        return res;
        
    }
};