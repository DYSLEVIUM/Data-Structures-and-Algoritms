#pragma GCC optimize("Ofast,fast-math")

#include <bits/stdc++.h>

#define deb(x) cout << '\n' \
                    << #x << " = " << x << '\n'

inline void setup() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

#ifdef LOCAL_PROJECT  // run with -DLOCAL_PROJECT during compilation
    freopen("input.txt", "r", stdin);
#else
#ifndef ONLINE_JUDGE  // runs automatically for supported online judges
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
#endif
}

inline void solve();

int main(int argc, char* argv[]) {
    setup();

    long long t = 1;
    // std::cin >> t;

    while (t--) solve();

    return 0;
}

//Compile: g++ -g -Wshadow -Wall main.cc -o a.exe -Ofast -Wno-unused-result
//Build: g++ -g -Wshadow -Wall main.cc -o a.exe -D_GLIBCXX_DEBUG
//Compile and run: g++ -g -Wshadow -Wall main.cc -o a.exe -Ofast -Wno-unused-result && a.exe

using namespace std;

vector<int> getDistance(vector<vector<int>> adjList, int startNode) {
    queue<int> q;

    q.push(startNode);

    vector<bool> visited(adjList.size(), false);  //  array to keep track of the nodes that have been visited

    visited[startNode] = true;  //  visiting the startNode

    vector<int> previous(adjList.size(), -1);  //  filling all the node to not having a previous node

    while (!q.empty()) {
        int node = q.front();  // getting the node
        q.pop();

        vector<int> neighbors = adjList[node];  //  getting all the neighbors of the node

        for (auto x : neighbors) {
            if (!visited[x]) {
                q.push(x);
                visited[x] = true;
                previous[x] = node;
            }
        }
    }

    return previous;
}

//  function to reconstruct the shortest path from startNode to endNode
vector<int> reconstructPath(int startNode, int endNode, vector<int> previous) {
    vector<int> path;  //  this will contain the path from startNode to endNode

    int currNode = endNode;
    while (currNode != startNode) {  //  we will traverse back until we get to the startNode
        if (currNode == -1) break;   // if there is no previous node, there cannot be a path
        path.push_back(currNode);
        currNode = previous[currNode];
    }

    reverse(path.begin(), path.end());  //  reversing the array as we went from the end to start

    //  checking if we actually got the path from startNode to endNode else returning empty array denoting no path
    if (*path.begin() == startNode) return path;
    return (vector<int>(0));
}

vector<int> bfs(vector<vector<int>> adjList, int startNode, int endNode) {
    vector<int> previous(adjList.size());  //  this array will keep all the previous

    previous = getDistance(adjList, startNode);  //  doing a bfs starting at node startNode

    return reconstructPath(startNode, endNode, previous);  //  returning the reconstructed path from startNode to endNode
}

void printGraph(vector<vector<int>> adjList) {
    for (int i = 0; i < adjList.size(); ++i) {
        cout << i + 1 << " -> ";
        for (int j = 0; j < adjList[i].size(); ++j) {
            cout << adjList[i][j] + 1 << ' ';
        }
        cout << '\n';
    }
}

inline void solve() {
    vector<vector<int>> adjList;  //	graph as adjency List

    //	building the graph
    adjList.emplace_back(vector<int>{1, 4});
    adjList.emplace_back(vector<int>{0, 2, 4});
    adjList.emplace_back(vector<int>{1, 3});
    adjList.emplace_back(vector<int>{2, 5, 4});
    adjList.emplace_back(vector<int>{0, 1, 3});
    adjList.emplace_back(vector<int>{3});

    vector<int> path = bfs(adjList, 0, 5);  // getting the shortest path

    for (auto x : path) {
        cout << x << "->";
    }
}
