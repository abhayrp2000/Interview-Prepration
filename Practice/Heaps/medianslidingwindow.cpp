//TLE

class Solution {
public:
    
    void rebalance(priority_queue<int> &maxH,priority_queue<int,vector<int>,greater<int> > &minH){
        if(maxH.size()>minH.size()+1){
            minH.push(maxH.top());
            maxH.pop();
        }else if(minH.size()>maxH.size()){
            maxH.push(minH.top());
            minH.pop();
        }
    }
    
    void remove(priority_queue<int> &maxH,int ele){
        vector<int> temp;
        
        bool found=false;
        while(!maxH.empty()){
            if(maxH.top()==ele && !found){
                maxH.pop();
                found=true;
                break;
            }else{
                temp.push_back(maxH.top());
                maxH.pop();
            }
        }
        
        
        
        for(auto val:temp){
            maxH.push(val);
        }
        
    }
    
    void removemin(priority_queue<int,vector<int>,greater<int> > &minH,int ele){
        vector<int> temp;
        bool found=false;
        while(!minH.empty()){
            if(minH.top()==ele){
                minH.pop();
                break;
            }else{
                temp.push_back(minH.top());
                minH.pop();
            }
        }
       
        
        
        for(auto val:temp){
            minH.push(val);
        }
       
    }
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> res(nums.size()-k+1);
        
        priority_queue<int> maxH;
        priority_queue<int,vector<int>,greater<int> > minH;
        
        
        for(int i=0;i<nums.size();i++){
            if(maxH.empty()||maxH.top()>=nums[i]){
                maxH.push(nums[i]);
            }else{
                minH.push(nums[i]);
            }
            
            rebalance(maxH,minH);
            
            
            
            if(i-k+1>=0){
                
             
                if(maxH.size()==minH.size()){
                    
                    res[i-k+1]=(maxH.top()/2.0)+(minH.top()/2.0);
                    
                }else{
                    res[i-k+1]=maxH.top();
                }
               
                int eleremove=nums[i-k+1];
                if(maxH.top()>=eleremove){
                    remove(maxH,eleremove);
                }else{
                    removemin(minH,eleremove);
                }
                rebalance(maxH,minH);
            }
        }
        return res;
    }
};