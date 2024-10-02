// https://leetcode.com/problems/online-stock-span

class StockSpanner {
public:
    stack<int>s;
    vector<int>v;
    StockSpanner() {
    }
    
    int next(int price) {
        v.push_back(price);
        while(!s.empty() && v[s.top()]<=price){
            s.pop();
        }
        int ans=0;
        if(s.empty()){
            ans=v.size();
        }
        else{
            ans=v.size()-s.top()-1;
        }
        s.push(v.size()-1);
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */