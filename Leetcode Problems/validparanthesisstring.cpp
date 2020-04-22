class Solution {
public:
    bool checkValidString(string s) {
        
        stack<char> brackets;
        stack<char> star;
        
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                brackets.push(i);
            }else if (s[i]=='*'){
                star.push(i);
            }else{//equal to )
                if(!brackets.empty()){
                    brackets.pop();
                }else if(!star.empty()){
                    star.pop();
                }else{
                    return false;
                }
            }
        }
        
        while(!brackets.empty() && !star.empty()){
            if(brackets.top()>star.top()){
                return false;
            }
            brackets.pop();
            star.pop();
        }
        
        return brackets.empty();
        
       
    }
};