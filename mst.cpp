#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Structure to represent an edge in the graph
struct Edge {
    int src, dest, weight;
};

// Function to compare edges based on their weights
struct CompareEdges {
    bool operator()(const Edge& a, const Edge& b) {
        return a.weight > b.weight;
    }
};

// Function to find the minimum spanning tree using Prim's algorithm
void findMinimumSpanningTree(vector<vector<pair<int, int>>>& graph) {
    int N = graph.size(); // Number of vertices in the graph
    vector<bool> visited(N, false); // Track visited vertices
    priority_queue<Edge, vector<Edge>, CompareEdges> pq; // Priority queue to store edges

    // Start with vertex 0
    visited[0] = true;

    // Add all edges of vertex 0 to the priority queue
    for (const auto& neighbor : graph[0]) {
        int v = neighbor.first;
        int weight = neighbor.second;
        pq.push({0, v, weight});
    }

    // Loop until the priority queue is empty
    while (!pq.empty()) {
        Edge currEdge = pq.top();
        pq.pop();
        int src = currEdge.src;
        int dest = currEdge.dest;
        int weight = currEdge.weight;

        // If the destination is already visited, skip the edge
        if (visited[dest])
            continue;

        // Mark the destination as visited
        visited[dest] = true;

        // Print the edge
        cout << "Edge: " << src << " - " << dest << ", Weight: " << weight << endl;

        // Add all edges of the destination vertex to the priority queue
        for (const auto& neighbor : graph[dest]) {
            int v = neighbor.first;
            int weight = neighbor.second;
            pq.push({dest, v, weight});
        }
    }
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

    cout << "Minimum Spanning Tree Edges:\n";
    findMinimumSpanningTree(graph);

    return 0;
}
