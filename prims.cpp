#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function to find the minimum spanning tree using Prim's algorithm
void findMinimumSpanningTree(vector<vector<pair<int, int>>>& graph) {
    int N = graph.size(); // Number of vertices in the graph
    vector<bool> visited(N, false); // Track visited vertices
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Priority queue to store edges

    int totalWeight = 0; // Track the total weight of the minimum spanning tree

    // Start with vertex 0
    visited[0] = true;

    // Add all edges of vertex 0 to the priority queue
    for (const auto& neighbor : graph[0]) {
        int v = neighbor.first;
        int weight = neighbor.second;
        pq.push({weight, v});
    }

    // Loop until all vertices have been visited
    while (!pq.empty()) {
        pair<int, int> currEdge = pq.top();
        pq.pop();
        int weight = currEdge.first;
        int v = currEdge.second;

        // If the vertex is already visited, skip it
        if (visited[v])
            continue;

        // Mark the vertex as visited
        visited[v] = true;

        // Add the weight of the edge to the total weight of the minimum spanning tree
        totalWeight += weight;

        // Add all edges of the vertex to the priority queue
        for (const auto& neighbor : graph[v]) {
            int u = neighbor.first;
            int weight = neighbor.second;
            if (!visited[u]) {
                pq.push({weight, u});
            }
        }
    }

    // Print the total weight of the minimum spanning tree
    cout << "Total weight of the minimum spanning tree: " << totalWeight << endl;
}

int main() {
    int N, E;
    cout << "Enter the number of vertices: ";
    cin >> N;
    cout << "Enter the number of edges: ";
    cin >> E;

    vector<vector<pair<int, int>>> graph(N);

    cout << "Enter the edges in the format 'source destination weight':\n";
    for (int i = 0; i < E; i++) {
        int src, dest, weight;
        cin >> src >> dest >> weight;
        graph[src].push_back({dest, weight});
        graph[dest].push_back({src, weight});
    }

    findMinimumSpanningTree(graph);

    return 0;
}
