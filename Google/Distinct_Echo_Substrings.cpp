// Problem Link - https://leetcode.com/problems/distinct-echo-substrings/description/

class Solution {
public:
    int distinctEchoSubstrings(string text) {
        int n = text.size();
        vector<int> copy(n + 1, 0);
        int res = 0;
        for(int i = 1; i < n; i++)
        {
            int l = 0, r = i, c = 0;
            while(r < n)
            {
                if(text[l++] == text[r++])
                {
                    c++;
                }
                else
                {
                    c = 0;
                }
                copy[r] = max(copy[r], c);
            }
        }
        for(int i = 1; i <= n / 2; i++)
        {
            int l = 0, r = i, c = 0;
            while(r < n)
            {
                if(text[l++] == text[r++])
                {
                    c++;
                }
                else
                {
                    c = 0;
                }
                if(c >= i && copy[r] < i * 2)
                {
                    res++;
                }
            }
        }
        return res;
    }
};
