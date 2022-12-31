Problem Link - leetcode.com/problems/evaluate-reverse-polish-notation/

class Solution {
public:
bool isOperator(string s){
    return s=="+"||s=="-"||s=="*"||s=="/";
}
    int evalRPN(vector<string>& tokens) {
        stack<long>st;
        for(auto& token:tokens){
            if(isOperator(token)){
                long x = st.top();
                st.pop();
                long y = st.top();
                st.pop();
                if(token=="+")
                st.push(y+x);
                else if(token=="-")
                st.push(y-x);
                else if(token=="*")
                st.push(y*x);
                else
                st.push(y/x);
            }else{
                st.push(stol(token));
            }
        }
        return st.top();
    }
};
