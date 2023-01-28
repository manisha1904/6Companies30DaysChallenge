// Problem Link - https://leetcode.com/problems/maximum-subarray-min-product/description/

typedef long long ll;
ll mod=1e9+7;
class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        int n=nums.size();
        vector<ll> pref(n+1,0);//storing the prefix sum
        pref[0]=0;
        for(int i=1;i<=n;i++)
        {
            pref[i]=nums[i-1]+pref[i-1];
        }
        vector<ll> right(n);//for storing the index which is smallest in the right of index i
        vector<ll> left(n);//for storing the index which is smallest in the left of index i
        right[n-1]=n;
        stack<ll> st1;
        stack<ll>st2;
        st1.push(n-1);
        for(int i=n-2;i>=0;i--)
        {
            while(!st1.empty() and nums[st1.top()]>=nums[i])
                st1.pop();
            if(st1.empty())
                right[i]=n;
            else
                right[i]=st1.top();
            st1.push(i);
        }
        left[0]=-1;
        st2.push(0);
        for(int i=1;i<n;i++)
        {
            while(!st2.empty() and nums[i]<=nums[st2.top()])
                st2.pop();
            if(st2.empty())
                left[i]=-1;
            else
                left[i]=st2.top();
                st2.push(i);
        }
        ll maxi=INT_MIN;
        for(int i=0;i<n;i++)
        {
            ll ans=(((pref[right[i]]-pref[left[i]+1]))*nums[i]);//considering  nums[i] smaller
            maxi=max(maxi,ans);//then finding the corresponding subbarray sum multiplying with nums[i]
        }                                  // and finding maximum by considering each element
        return maxi%mod;
    }
};

