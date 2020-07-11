class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int> > res;
        queue<vector<int> > q;
        
        q.push(vector<int>());
        
        for(auto val:nums){
            int n=q.size();
            
            for(int i=0;i<n;i++){
                vector<int> old=q.front();
                q.pop();
                
                for(int j=0;j<=old.size();j++){
                    vector<int> newar(old);
                    newar.insert(newar.begin()+j,val);
                    
                    if(newar.size()==nums.size()){
                        res.push_back(newar);
                    }else{
                        q.push(newar);
                    }
                }
            }
        }
        
        return res;
        
    }
};