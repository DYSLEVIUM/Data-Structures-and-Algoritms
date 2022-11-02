class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> valid_genes(bank.begin(), bank.end());
  
        queue<string> qu;
        qu.push(start);

        unordered_set<string> vis;
        vis.insert(start);

        int cnt = 0;
        while(!qu.empty()) {
            int sz = qu.size();
            while(sz--) {
                string fr = qu.front();
                qu.pop();

                if(fr == end) return cnt;

                for(int i = 0; i < fr.size(); ++i) {
                    for(const char & g : "ACGT") {
                        string neighbour = fr;
                        neighbour[i] = g;
                        if(!vis.count(neighbour) && valid_genes.count(neighbour)) {
                            qu.push(neighbour);
                            vis.insert(neighbour);
                        }
                    }
                }
            }
            ++cnt;
        }

        return -1;
    }
};
