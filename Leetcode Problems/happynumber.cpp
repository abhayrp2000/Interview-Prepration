class Solution {
public:
    
    int generateNumber(int n){
        int curr=0;
        while(n!=0){
            int temp=n%10;
            curr=curr+(temp*temp);
            n=n/10;
        }
        return curr;
        
    }
    bool isHappy(int n) {
        
        if(n==1){
            return true;
        }
        map<int,int> mp;
        mp.insert({n,1});
        while(true){
            int res=generateNumber(n);
            n=res;
            if(n==1){
                return true;
            }
            if(mp.find(n)!=mp.end()){
                return false;
            }else{
                mp.insert({n,1});
            }
            
            
        }
        
    }
};