constexpr int TOTAL_BITS = 31;
class Trie {
    class Node {
        vector<Node *> m_nodes{2, nullptr};
        friend class Trie;
    };
    Node *m_root = nullptr;
public:
    void insert(const int &n) {
        if(!m_root) {
            m_root = new Node;
        }

        Node *node = m_root;
        for(int i = TOTAL_BITS; i >= 0; --i) {
            int bit = (n >> i) & 1;
            if(!node->m_nodes[bit]) {
                node->m_nodes[bit] = new Node;
            }
            node = node->m_nodes[bit];
        }
    }

    int query(const int &x) {
        if(!m_root) {
            return -1;
        }

        Node *node = m_root;
        int ans = 0;
        for(int i = TOTAL_BITS; i >= 0; --i) {
            int bit = (x >> i) & 1;
            if(bit) {
                if(node->m_nodes[0]) {
                    ans |= (1 << i);
                    node = node->m_nodes[0];
                } else {
                    node = node->m_nodes[1];
                }
            } else {
                if(node->m_nodes[1]) {
                    ans |= (1 << i);
                    node = node->m_nodes[1];
                } else {
                    node = node->m_nodes[0];
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        // using dry trie gives TLE
        int nn = nums.size(), nq = queries.size();

        vector<vector<int>> queriess(nq);
        for(int i = 0; i < nq; ++i) {
            auto query = queries[i];
            queriess[i] = {query[1], query[0], i};
        }
        sort(queriess.begin(), queriess.end());
        sort(nums.begin(), nums.end());

        Trie tr;
        int j = 0;
        vector<int> ans(nq);
        for(const auto &query : queriess) {
            int m = query[0], x = query[1], pos = query[2];
            // lazy insertion
            while(j < nn && nums[j] <= m) {
                tr.insert(nums[j++]);
            }
            ans[pos] = tr.query(x);
        }

        return ans;
    }
};
