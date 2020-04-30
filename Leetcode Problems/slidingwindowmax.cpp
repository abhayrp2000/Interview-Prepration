class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& a, int k) {
        
        vector<int> res;
        deque<int> q;
        
        int i;
        for(i=0;i<k;i++){
            while(!q.empty() && a[i]>=a[q.back()]){
                q.pop_back();
            }
            q.push_back(i);
        }
        
        for(;i<a.size();i++){
            res.push_back(a[q.front()]);
            while(!q.empty() && q.front()<=(i-k)){
                q.pop_front();
            }
            
            while(!q.empty() && a[i]>=a[q.back()]){
                q.pop_back();
            }
            q.push_back(i);
        }
        res.push_back(a[q.front()]);
        return res;
        
    }
};