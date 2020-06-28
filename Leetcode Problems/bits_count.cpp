class Solution {
public:
    vector<int> countBits(int num) {
        
        vector<int> res;
        for(int i=0;i<=num;i++){
            res.push_back(__builtin_popcount(i));
        }
        return res;
        
    }
};