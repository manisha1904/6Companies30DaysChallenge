// Problem Link - https://leetcode.com/problems/closest-prime-numbers-in-range/description/

class Solution {
public:
bool isPrime(int x){
    if(x<=1)
    return false;
    for(int i=2;i*i<=x;i++){
        if(x%i==0)return false;
    }
    return true;
}
    vector<int> closestPrimes(int left, int right) {
        vector<int>ans;
        vector<int>prime;
        for(int i=left;i<=right;i++){
            if(isPrime(i))
            prime.push_back(i);
        }
        int n = prime.size();
        int diff=INT_MAX,first=-1,second=-1;
        for(int i=0;i<n-1;i++){
            int curr=prime[i+1]-prime[i];
            if(curr<diff){
                diff=curr;
                first=prime[i];
                second=prime[i+1];
            }
        }
        ans.push_back(first);
        ans.push_back(second);
        return ans;

    }
};
