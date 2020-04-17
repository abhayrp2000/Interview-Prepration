class Solution {
public:
    
    int typeOf(char c){
        if(c=='[' || c==']') return 0;
        if(c=='{' || c=='}') return 1;
        if(c=='(' ||c==')') return 2;
        
        return 0;
    }
    bool isValid(string s) {
        
        if(s.size()==0){
            return true;
        }
        
        
        stack<char> S;
        
        for(int i=0;i<s.size();i++){
            if(s[i]=='{'||s[i]=='[' || s[i]=='('){
                S.push(s[i]);
            }else
                if(!S.empty() && typeOf(S.top())==typeOf(s[i]))
                    S.pop();
                else
                    return false;
            
                
            }
        
        
    // while(!S.empty()){
    //     cout<<S.top()<<endl;
    //     S.pop();
    // }
    
    return S.empty();
    }
        
    
};