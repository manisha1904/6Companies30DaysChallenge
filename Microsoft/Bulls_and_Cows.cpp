Problem Link - leetcode.com/problems/bulls-and-cows/

class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char,int>mp_secret,mp_guess;
        string ans="";
        int bulls=0;
        int cows=0;
        int n = secret.size();
        for(int i=0;i<n;i++){
            if(secret[i]==guess[i])
                bulls++;
            else{
                mp_secret[secret[i]]++;
                mp_guess[guess[i]]++;
            }
        }
        for(auto& x:mp_secret){
            if(mp_guess.find(x.first)!=mp_guess.end()){
                cows += min(x.second,mp_guess[x.first]);
            }
        }
        ans += to_string(bulls) + "A" + to_string(cows) + "B";
        return ans;
    }
};
