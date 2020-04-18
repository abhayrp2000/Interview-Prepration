class Solution {
public:
    bool isPowerOfTwo(int n) {
        long long int i=1;
        while(i<n){
            i=i*2;
        }
        
        if(i==n){
            return true;
        }else{
            return false;
        }
    }
};