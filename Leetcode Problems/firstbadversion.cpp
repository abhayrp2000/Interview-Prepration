// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        
         int ans=0;
        long long int s=1;
        long long int e=n;
        
        while(s<=e){
            long long int mid=(s+e)/2;
            if(isBadVersion(mid)){
                ans=mid;
                e=mid-1;
            }else{
                s=mid+1;
            }
        }
        return ans;
        
    }
};