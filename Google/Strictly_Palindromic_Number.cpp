// Problem Link - https://leetcode.com/problems/strictly-palindromic-number/description/

class Solution {
public:
    bool palindromeCheck(string s){
        int i=0,j=s.length()-1;
        while(i<j){
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    bool baseConversion(int n,int b){
        string s="";
        while(n){
            int rem = n%b;
            s+=(rem+'0');
            n/=b;
        }
        return palindromeCheck(s);
    }
    bool isStrictlyPalindromic(int n) {
        for(int i=2;i<=n-2;i++){
            if(!baseConversion(n,i))
                return false;
        }
        return true;
    }
};
