// Problem Link - https://leetcode.com/problems/fraction-to-recurring-decimal/description/

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(!numerator)
        return "0";
        string ans="";
        if(numerator>0 ^ denominator>0)
        ans+="-";
        long num = labs(numerator);
        long den = labs(denominator);
        long r = num%den;
        long q = num/den;
        ans+=to_string(q);
        if(r==0)
        return ans;
        ans+=".";
        unordered_map<long,int>mp;
        while(r!=0){
            if(mp.find(r)!=mp.end()){
                int pos = mp[r];
                ans.insert(pos,"(");
                ans+=")";
                break;
            }else{
                mp[r]=ans.size();
                r*=10;
                q=r/den;
                r%=den;
                ans+=to_string(q);
            }
        }
        return ans;
    }
};
