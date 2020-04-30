class Solution {
public:
    string removeDuplicates(string S) {
        stack<char> st;
        
        for(auto val:S){
            if(st.empty()){
                st.push(val);
                continue;
            }
            
            if(!st.empty() && st.top()==val){
                st.pop();
            }else{
                st.push(val);
            }
                
        }
        
        string res="";
        while(!st.empty()){
            res=st.top()+res;
            st.pop();
        }
        
        return res;
    }
};