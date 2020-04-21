class Solution {
public:
    
    int movescalc(vector<int> &nums,int mid){
        int val=nums[mid];
        int moves=0;
        int n=nums.size();
        
        for(int i=0;i<n;i++){
            if(i==mid){
                continue;
            }else{
                moves+=(abs(nums[mid]-nums[i]));
            }
        }
        return moves;
    }
    int minMoves2(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        int n=nums.size();
        
        
        
        if(n%2==0){
           int val1=movescalc(nums,(n/2)-1);
            int val2=movescalc(nums,n/2);
                
                return min(val1,val2);
            
            
        }else{
            int val=movescalc(nums,n/2);
            return val;
        }
        
       
    }
};