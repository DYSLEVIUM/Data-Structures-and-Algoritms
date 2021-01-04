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

vector<bool> visited((int)1e5, 0);

int countComponents = 0;              //counts the number of connected components
vector<int> components((int)1e5, 0);  //	array to store the component number of nodes

void dfs(vector<vector<int>> adjList, int startNode) {
    visited[startNode] = true;  //	setting currentNode to be visited

    components[startNode] = countComponents;  //	marking the component number

    vector<int> neighbors = adjList[startNode];  // getting all the nodes connected to currentNode

    for (auto x : neighbors) {
        if (!visited[x]) dfs(adjList, x);  //	dfs on all other nodes connected to currentNode and isn't visited
    }
}

//	total connected components is the number of times the dfs is called (it means that the counter goes up everytime we perform dfs on an unvisited node)
int findConnectedComponents(vector<vector<int>> adjList) {
    for (int i = 0; i < adjList.size(); ++i)
        if (!visited[i]) {
            ++countComponents;
            dfs(adjList, i);
        }

    return countComponents;
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
    countComponents = 0;
    fill(components.begin(), components.end(), -1);  //	marking all the nodes to be initially not connected
    fill(visited.begin(), visited.end(), false);     //	marking all the nodes to be initially unvisited, if the visited array was used before

    vector<vector<int>> adjList;  //	graph as adjency List

    //	building the graph
    adjList.emplace_back(vector<int>{1, 4});
    adjList.emplace_back(vector<int>{0, 2, 4});
    adjList.emplace_back(vector<int>{1, 3});
    adjList.emplace_back(vector<int>{2, 4});
    adjList.emplace_back(vector<int>{0, 1, 3});
    adjList.emplace_back(vector<int>{});

    visited.reserve(adjList.size());  //	size of the visited array is total nodes in the list
}
