#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
// Structure to represent a weighted edge
struct Edge {
    int destination;
    int weight;
};

// Function to find the shortest path using Dijkstra's algorithm
void shortestPath(const vector<vector<Edge>>& graph, int source) {
    int numVertices = graph.size();
    vector<int> distance(numVertices, INT_MAX); // Initialize distances to infinity
    vector<bool> visited(numVertices, false);   // Initialize visited array
    // Priority queue to store vertices based on their distance
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    distance[source] = 0;  // Distance of source vertex from itself is always 0
    pq.push(make_pair(0, source));  // Push source vertex to the priority queue

    while (!pq.empty()) {
        int u = pq.top().second;  // Get the vertex with the minimum distance
        pq.pop();
        visited[u] = true;  // Mark the vertex as visited

        // Update the distance of adjacent vertices
        for (const Edge& edge : graph[u]) {
            int v = edge.destination;
            int weight = edge.weight;

            // If a shorter path is found, update the distance
            if (!visited[v] && distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                pq.push(make_pair(distance[v], v));  // Push the updated distance to the priority queue
            }
        }
    }

    // Print the shortest distances from the source vertex to all other vertices
    cout << "Shortest distances from vertex " << source << ":" << endl;
    for (int i = 0; i < numVertices; ++i) {
        cout << "Vertex " << i << ": " << distance[i] << endl;
    }
}

int main() {
    int numVertices, numEdges;
    cout << "Enter the number of vertices: ";
    cin >> numVertices;
    cout << "Enter the number of edges: ";
    cin >> numEdges;

    vector<vector<Edge>> graph(numVertices);

    cout << "Enter the edges (source destination weight):" << endl;
    for (int i = 0; i < numEdges; ++i) {
        int source, destination, weight;
        cin >> source >> destination >> weight;
        graph[source].push_back({destination, weight});
    }

    int sourceVertex;
    cout << "Enter the source vertex: ";
    cin >> sourceVertex;

    shortestPath(graph, sourceVertex);

    return 0;
}
