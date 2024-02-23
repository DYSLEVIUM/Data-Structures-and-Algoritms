#pragma GCC optimize("O3", "unroll-loops")

class Solution {
public:
    int findCheapestPrice(const int & n, const vector<vector<int>> & flights, const int & src, const int & dst, const int & k) {
        cin.tie(nullptr)->sync_with_stdio(false);

        constinit static int INF = 0x3f3f3f;

        vector<vector<pair<int, int>>> edges(n);
        for(const auto & flight: flights) {
            edges[flight[0]].emplace_back(flight[1], flight[2]);
        }

        struct Route {
            Route(const int & node, const int & cost, const int & stops): node(node), cost(cost), stops(stops) {}
            int node, cost, stops;
        };

        // dijkstra's implementation, O(V²) better use BFS to find shortest path in O(V+E)
        auto heap_compare = [](const Route & lhs, const Route & rhs){
            return lhs.cost < rhs.cost;
        };

        vector<int> min_dist(n, INF);
        min_dist[src] = 0;

        priority_queue<Route, vector<Route>, decltype(heap_compare)> min_heap(heap_compare);
        min_heap.push(Route(src, 0, 0));

        while(!min_heap.empty()) {
            const Route route = min_heap.top();
            min_heap.pop();

            if(min_dist[route.node] < route.cost || route.stops > k) {
                continue;
            }

            for(const auto & [to, price]: edges[route.node]) {
                int new_dist = min_dist[route.node] + price;
                if(new_dist < min_dist[to]) {
                    min_dist[to] = new_dist;
                    min_heap.push(Route(to, new_dist, route.stops + 1));
                }
            }
        }

        return min_dist[dst] == INF ? -1 : min_dist[dst];
    }
};
