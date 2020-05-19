class StockSpanner {
public:
    
    typedef struct Prices{
        int price;
        int span;
    };
    
    stack<Prices> st;
    
    StockSpanner() {
        
    }
    
    int next(int price) {
        
        Prices stock;
        stock.price = price;
        stock.span = 1;
        while( !st.empty() && st.top().price <= price ){
            stock.span += st.top().span;
            st.pop();
        }
        st.push(stock);
        return stock.span;
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
