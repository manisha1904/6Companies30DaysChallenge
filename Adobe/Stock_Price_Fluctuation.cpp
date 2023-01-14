// Problem Link - https://leetcode.com/problems/stock-price-fluctuation/description/

class StockPrice {
public:
map<int,int>mp;
multiset<int>ms;
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        if(mp.find(timestamp)!=mp.end())
        ms.erase(ms.find(mp[timestamp]));
        mp[timestamp]=price;
        ms.insert(price);
    }
    
    int current() {
        return mp.rbegin()->second;
    }
    
    int maximum() {
        return *ms.rbegin();
    }
    
    int minimum() {
        return *ms.begin();
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
