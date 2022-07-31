class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        auto dijkstra = [&](const int &src){
            vector<int> dist(n, INT_MAX);
            dist[src] = 0;
            
            using pii = pair<int, int>;
            priority_queue<pii, vector<pii>, greater<pii>> pq;
            pq.push({ 0, src });
            while(!pq.empty()) {
                auto &[curr_dist, curr_node] = pq.top();
                pq.pop();
                
                // if we already have the best answer
                if(curr_dist > dist[curr_node]) {
                    continue;
                }
                
                // atmost one edge, so no loop required
                int other_node = edges[curr_node];
                
                if(other_node == -1) {
                    continue;
                }
                
                int new_dist = dist[curr_node] + 1;
                if (new_dist < dist[other_node]) {
                  dist[other_node] = new_dist;
                  pq.push({ new_dist, other_node });
                }
            }
            
            return dist;
        };
        
        // single source shortest path with source
        auto sssp1 = dijkstra(node1), sssp2 = dijkstra(node2);
        
        int minn_dist = INT_MAX;
        int idx = -1;
        
        // checking every node to be the meeting point
        for(int i = 0; i < n; ++i) {
            int curr_dist = max(sssp1[i], sssp2[i]);
            if(curr_dist <= minn_dist) {
                minn_dist = max(sssp1[i], sssp2[i]);
                idx = min(idx, i);
            }
        }
        
        return idx;
    }
};
