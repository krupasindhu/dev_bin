#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// BFS is a graph traversal mechanism
// Most important is the adjacent node of all tne nodes
// To store we need adjMatrix.
// Example For 1 adj are {2, 5}
//             2 adj are {1, 3, 5}
//             3 adj are {2, 4}
//             4 adj are {5, 3}
//             5 adj are {2, 1, 4}
//      1
//   /    \
//  2------5
//  |  /   |
//  3------4
// output should be : 1 2 5 3 4
// Another Input should be starting Node : Lets assume 1 is the starting node
// for this graph
// Intial configuration : 
// 1: Queue 2: Data structure to keep track of the visited node.
// Approch : Insert the start elelm into the queue
//           Marked as visited
//           check the adj of the element and inserted them and start traversaing
//           poped the top most elem from queue and store in a res DB which will be stored in
//           travesal order
//
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> bfsOfGraph(vector<int> adjMatrix[], int V) {
    int vis[V+1]; // Create a visited array of size V+1 to accommodate 1-indexed vertices
    for(int i = 0; i < V+1; i++) {
        vis[i] = 0;
    }

    vis[1] = 1; // Start BFS from vertex 1 (which corresponds to index 1)

    queue<int> q;
    q.push(1);
    vector<int> bfs;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        bfs.push_back(node);

        for (auto it : adjMatrix[node]) {
            if (!vis[it]) {
                vis[it] = 1;
                q.push(it);
            }
        }
    }
    return bfs;
}

void addEdge(vector<int> adjMatrix[], int u, int v) {
    adjMatrix[u].push_back(v);
    adjMatrix[v].push_back(u);
}

void printAns(vector<int> &ans) {
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
}

int main() {
    cout << " Demonstrating the BFS Graph Traversal" << endl;

    int V = 5; // number of vertices
    vector<int> adjMatrix[V+1];

    // Add edges according to the adjacency list given in the problem statement
    addEdge(adjMatrix, 1, 2);
    addEdge(adjMatrix, 1, 5);
    addEdge(adjMatrix, 2, 3);
    addEdge(adjMatrix, 2, 5);
    addEdge(adjMatrix, 3, 4);
    addEdge(adjMatrix, 4, 5);

    vector<int> res = bfsOfGraph(adjMatrix, V);

    printAns(res); // Output: 1 2 5 3 4

    return 0;
}