constinit static int INF = 0x3f3f3f;

class Graph {
public:
    Graph(const int & n, const vector<vector<int>> & edges) : n_m{n} {
        gr_m = vector<vector<int>>(n, vector<int>(n, INF));
        for(const auto & edge: edges) {
            int from = edge[0], to = edge[1], weight = edge[2];
            gr_m[from][to] = weight;
        }

        for(int i = 0; i < n; ++i) {
            gr_m[i][i] = 0;
        }

        floyd_warshall();
    }
    
    void addEdge(const vector<int> & edge) {
        int from = edge[0], to = edge[1], weight = edge[2];
        for(int i = 0; i < n_m; ++i) {
            for(int j = 0; j < n_m; ++j) {
                gr_m[i][j] = min(gr_m[i][j], gr_m[i][from] + gr_m[to][j] + weight);
            }
        }
    }
    
    int shortestPath(const int & node1, const int & node2) {
        return gr_m[node1][node2] == INF ? -1 : gr_m[node1][node2];
    }

private:
    void floyd_warshall() {
        for(int i = 0; i < n_m; ++i) {
            for(int j = 0; j < n_m; ++j) {
                for(int k = 0; k < n_m; ++k) {
                    gr_m[j][k] = min(gr_m[j][k], gr_m[j][i] + gr_m[i][k]);
                }
            }
        }
    }

    int n_m;
    vector<vector<int>> gr_m;
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */
