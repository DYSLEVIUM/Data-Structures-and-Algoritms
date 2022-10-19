class Cashier {
public:
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) : m_n(n), m_discount((100 - (double)discount) / 100) {
        for(int i = 0; i < products.size(); ++i) m_prod_prices[products[i]] = prices[i];
    }
    
    double getBill(vector<int> product, vector<int> amount) {
        ++m_cnt;

        double total = 0;
        for(int i = 0; i < product.size(); ++i) total += m_prod_prices[product[i]] * amount[i];
        
        if(m_cnt == m_n) {
            m_cnt = 0;
            total = total * m_discount;
        }

        return total;
    }
private:
    int m_cnt = 0;
    const int m_n;
    const double m_discount;
    unordered_map<int, int> m_prod_prices;
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */
