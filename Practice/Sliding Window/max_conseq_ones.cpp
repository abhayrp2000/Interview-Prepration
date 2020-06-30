class Solution {
public:
    int longestOnes(vector<int>& arr, int k) {
        
        int onescount=0;
        
        int start=0;
        int len=0;
        int maxfreq=0;
        
        for(int end=0;end<arr.size();end++){
            if(arr[end]==1){
                onescount++;
            }
            maxfreq=max(maxfreq,onescount);
            
            if(end-start+1-onescount>k){
                if(arr[start]==1){
                    onescount--;
                    
                }
                start++;
                
            }
            len=max(len,end-start+1);
        }
        
        return len;
    }
};