#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

// Structure to represent a vertex and its corresponding distance
struct Vertex {
    int id;
    int distance;
};

// Function to compare vertices based on their distances
struct CompareVertices {
    bool operator()(const Vertex& a, const Vertex& b) {
        return a.distance > b.distance;
    }
};

// Function to find the shortest paths from a source vertex to all other vertices
void findShortestPaths(vector<vector<pair<int, int>>>& graph, int source) {
    int N = graph.size(); // Number of vertices in the graph
    vector<int> distances(N, numeric_limits<int>::max()); // Array to store distances
    vector<bool> visited(N, false); // Track visited vertices
    priority_queue<Vertex, vector<Vertex>, CompareVertices> pq; // Priority queue to store vertices

    // Set the distance of the source vertex to 0 and add it to the priority queue
    distances[source] = 0;
    pq.push({source, 0});

    // Loop until the priority queue is empty
    while (!pq.empty()) {
        Vertex currVertex = pq.top();
        pq.pop();
        int v = currVertex.id;
        int dist = currVertex.distance;

        // If the vertex is already visited, skip it
        if (visited[v])
            continue;

        // Mark the vertex as visited
        visited[v] = true;

        // Update the distances of the neighboring vertices
        for (const auto& neighbor : graph[v]) {
            int u = neighbor.first;
            int weight = neighbor.second;
            int newDist = dist + weight;

            // If a shorter path is found, update the distance and add the vertex to the priority queue
            if (newDist < distances[u]) {
                distances[u] = newDist;
                pq.push({u, newDist});
            }
        }
    }

    // Print the shortest distances
    cout << "Shortest distances from vertex " << source << ":\n";
    for (int i = 0; i < N; i++) {
        cout << "Vertex " << i << ": " << distances[i] << endl;
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
    }

    int source;
    cout << "Enter the source vertex: ";
    cin >> source;

    findShortestPaths(graph, source);

    return 0;
}
