class StockSpanner {
public:
    
    typedef struct Prices{
        int curr;
        int span;
    };
    
    Prices prices[10005];
    int days;
    
    StockSpanner() {
        days = 0;
    }
    
    int next(int price) {
        prices[days].curr = price;
        int cnt = 1;
        int i = days - 1;
        while( i >= 0 && prices[i].curr <= price ){
            int jmp = prices[i].span;
            i -= jmp ;
            cnt += jmp;
        }
        prices[days].span = cnt;
        days++;
        return cnt;
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
