class StockSpanner {
public:
    stack<pair<int, int>> st;
    int i = -1;
    StockSpanner() { i = -1; }

    int next(int price) {
        i += 1;
        int ans;
        while (!st.empty() && st.top().first <= price) {
            st.pop();
        }
        int val;
        if (st.empty()) {
            val = -1;
        } else {
            val = st.top().second;
        }
        ans = i - val;
        st.push({price, i});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */