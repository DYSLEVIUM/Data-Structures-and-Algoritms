class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;
        
        vector<vector<pair<int, int>>> gr(n);
        for(auto& road : roads) {
            int u = road[0], v = road[1], time = road[2];
            gr[u].push_back({ v, time });
            gr[v].push_back({ u, time });
        }
        
        using ll = long long;
        using pll = pair<ll, ll>;
        
        priority_queue<pll, vector<pll>, greater<pll>> min_heap;    //  { dist, node }
        min_heap.push({0, 0});
        
        vector<ll> dist(n, LONG_LONG_MAX);
        dist[0] = 0;
        
        vector<int> ways(n);
        ways[0] = 1;
        
        while(!min_heap.empty()) {
            auto [curr_dist, curr_node] = min_heap.top();
            min_heap.pop();
            
            for(auto &[neighbour, time] : gr[curr_node]) {
                if(dist[neighbour] > curr_dist + time) {
                    dist[neighbour] = curr_dist + time;
                    min_heap.push({ dist[neighbour], neighbour });
                    
                    ways[neighbour] = ways[curr_node];
                } else if(dist[neighbour] == curr_dist + time) {
                    ways[neighbour] = ways[neighbour] + ways[curr_node];
                    ways[neighbour] %= MOD;
                }
            }
        }
        
        return ways[n - 1];
    }
};
