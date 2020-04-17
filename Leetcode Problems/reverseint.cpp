class Solution {
public:
    int reverse(int x) {
        
        long long signed int result=0;
        while(x!=0){
            int rem=x%10;
            result=result*10+rem;
            x=x/10;
        }
        if(result>2147483647||result<-2147483647){
            return 0;
        }
        return result;
        
    }
};