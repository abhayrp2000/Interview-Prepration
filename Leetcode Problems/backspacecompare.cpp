string formattedString(string s){
    string res="";
    for(char c : s){
        if(c=='#' && !res.empty()){
            res.pop_back();
        }else if(c!='#'){
            res=res+c;
        }
    }
    return res;
}

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        
        
        return formattedString(S)==formattedString(T);
        
    }
};