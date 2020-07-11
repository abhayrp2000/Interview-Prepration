class Solution {
public:
    
    struct profitCompare{
        bool operator()(const pair<int,int> &x,const pair<int,int> &y){
            return x.first<y.first;
        }
    };
    
    struct capitalCompare{
        bool operator()(const pair<int,int> &x,const pair<int,int> &y){
            return x.first>y.first;
        }
    };
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,profitCompare> maxProfit;
        priority_queue<pair<int,int>,vector<pair<int,int>>,capitalCompare> minCapital;
        
        for(int i=0;i<Capital.size();i++){
            minCapital.push(make_pair(Capital[i],i));
        }
        
        for(int i=0;i<k;i++){
            
            while(!minCapital.empty() && minCapital.top().first<=W){
                auto val=minCapital.top();
                int index=val.second;
                maxProfit.push(make_pair(Profits[index],index));
                minCapital.pop();
            }
            
            if(maxProfit.empty()){
                break;
            }
            
            W=W+maxProfit.top().first;
            maxProfit.pop();
            
        }
        
        return W;
        
    }
};