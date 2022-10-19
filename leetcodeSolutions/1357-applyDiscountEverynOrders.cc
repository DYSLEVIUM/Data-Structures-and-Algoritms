class Cashier {
public:
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) : m_n(n), m_discount(discount) {
        for(int i = 0; i < products.size(); ++i) m_prod_prices[products[i]] = prices[i];
    }
    
    double getBill(vector<int> product, vector<int> amount) {
        ++m_cnt;

        double total = 0;
        for(int i = 0; i < product.size(); ++i) total += m_prod_prices[product[i]] * amount[i];
        
        if(m_cnt == m_n) {
            m_cnt = 0;
            cout << total << ' ';

            total = total * ((100 - (double)m_discount) / 100);
        }

        return total;
    }
private:
    int m_n, m_discount, m_cnt = 0;
    unordered_map<int, int> m_prod_prices;
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */
