// Problem Link - https://leetcode.com/problems/distant-barcodes/description/

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        priority_queue<pair<int,int>>pq;
        unordered_map<int,int>mp;
        for(auto& barcode:barcodes){
            mp[barcode]++;
        }
        for(auto& x:mp){
            pq.push({x.second,x.first});
        }
        vector<int>res(barcodes.size());
        pair<int,int>p=pq.top();
        res[0]=p.second;
        pq.pop();
        p.first--;
        if(p.first>0){
            pq.push({p.first,p.second});
        }
        int i=1;
        while(!pq.empty()){
            p = pq.top();
            pq.pop();
            if(p.second==res[i-1]){
                pair<int,int>temp = pq.top();
                pq.pop();
                res[i]=temp.second;
                temp.first--;
                if(temp.first>0)
                pq.push(temp);
                pq.push(p);
            }else{
                res[i]=p.second;
                p.first--;
                if(p.first>0){
                    pq.push(p);
                }
            }
            i++;
        }
        return res;
    }
};

