// Problem Link - https://leetcode.com/problems/restore-ip-addresses/description/

class Solution {
public:
    void solve(int i,int counter, vector<string>&output,string s,string temp){
        if(counter==5 && temp.length()==s.length()+3){
            output.push_back(temp);
            return;
        }
        if(counter>4 || i>=s.length()){
            return;
        }
        solve(i+1,counter+1,output,s,temp+s[i]+(counter==4?"":"."));
        if(s[i]=='0'){
            return;
        }
        solve(i+2,counter+1,output,s,temp+s[i]+s[i+1]+(counter==4?"":"."));
        int num=stoi(s.substr(i,3));
        if(num<=255){
            solve(i+3,counter+1,output,s,temp+s[i]+s[i+1]+s[i+2]+(counter==4?"":"."));
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string>output;
        solve(0,1,output,s,"");
        return output;
        
    }
};
