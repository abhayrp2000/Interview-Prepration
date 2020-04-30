class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int i=0;
        int n=heights.size();
        
        stack<int> s;
        
        
        int area=0;
        
        while(i<n){
            if(s.empty()||heights[s.top()]<=heights[i]){
                s.push(i);
                i++;
            }else{
                int index=s.top();
                s.pop();
                if(s.empty()){
                    area=max(area,heights[index]*i);
                }else{
                    area=max(area,heights[index]*(i-s.top()-1));
                }
               
            }
        }
        
        while(!s.empty()){
            int index=s.top();
            s.pop();
            if(s.empty()){
                area=max(area,heights[index]*i);
            }else{
                area=max(area,heights[index]*(i-s.top()-1));
            }
        }
        
        return area;
        
    }
};