constinit static int INF = 0x3f3f3f;

class Solution {
public:
    int numBusesToDestination(const vector<vector<int>>& routes, const int& source, const int& target) {
        if(source == target) {
            return 0;
        }

        unordered_map<int, vector<int>> adj;
        for(int i = 0; const auto & route : routes) {
            for(const int & stop : route) {
                adj[stop].push_back(i);
            }
            ++i;
        }

        queue<int> qu;
        unordered_set<int> vis;
        for(int & route: adj[source]) {
            qu.push(route);
            vis.insert(route);
        }

        int ans = 1;
        while(!qu.empty()) {
            int sz = qu.size();
            while(sz--) {
                int route = qu.front();
                qu.pop();

                for(const auto & stop: routes[route]) {
                    if(stop == target) {
                        return ans;
                    }
                
                    for(const auto next_route: adj[stop]) {
                        if(!vis.count(next_route)) {
                            vis.insert(next_route);
                            qu.push(next_route);
                        }
                    }
                }
            }
            ++ans;
        }

        return -1;
    }
};
