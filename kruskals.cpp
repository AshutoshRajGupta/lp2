#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Structure to represent an edge in the graph
struct Edge
{
    int src, dest, weight;
};

// Function to compare edges based on their weights
bool compareEdges(const Edge &a, const Edge &b)
{
    return a.weight < b.weight;
}

// Function to find the parent of a vertex
int findParent(vector<int> &parent, int v)
{
    if (parent[v] == v)
        return v;
    return findParent(parent, parent[v]);
}

// Function to perform union of two sets
void unionSets(vector<int> &parent, int x, int y)
{
    int parentX = findParent(parent, x);
    int parentY = findParent(parent, y);
    parent[parentX] = parentY;
}

// Function to find the minimum spanning tree using Kruskal's algorithm
void findMinimumSpanningTree(vector<Edge> &edges, int V)
{
    vector<Edge> result;   // Store the edges of the minimum spanning tree
    vector<int> parent(V); // Array to store the parent of each vertex

    // Initialize parent array
    for (int i = 0; i < V; i++)
        parent[i] = i;

    // Sort edges in non-decreasing order of weights
    sort(edges.begin(), edges.end(), compareEdges);

    // Iterate through all edges in the sorted order
    for (const auto &edge : edges)
    {
        int srcParent = findParent(parent, edge.src);
        int destParent = findParent(parent, edge.dest);

        // If including the current edge does not form a cycle, add it to the result
        if (srcParent != destParent)
        {
            result.push_back(edge);
            unionSets(parent, srcParent, destParent);
        }
    }

    // Print the edges of the minimum spanning tree
    cout << "Minimum Spanning Tree Edges:\n";
    for (const auto &edge : result)
    {
        cout << "Edge: " << edge.src << " - " << edge.dest << ", Weight: " << edge.weight << endl;
    }
}

int main()
{
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    vector<Edge> edges(E);

    cout << "Enter the edges in the format 'source destination weight':\n";
    for (int i = 0; i < E; i++)
    {
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
    }

    findMinimumSpanningTree(edges, V);

    return 0;
}


/*#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int src, dest, weight;
};

struct Graph {
    int V;
    vector<Edge> edges;
};

bool compare(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

int findParent(vector<int>& parent, int i) {
    if (parent[i] == i)
        return i;
    return findParent(parent, parent[i]);
}

void unionSets(vector<int>& parent, int x, int y) {
    int xSet = findParent(parent, x);
    int ySet = findParent(parent, y);
    parent[ySet] = xSet;
}

void kruskalsMST(const Graph& graph) {
    vector<Edge> result;
    vector<int> parent(graph.V);

    for (int i = 0; i < graph.V; i++)
        parent[i] = i;

    vector<Edge> sortedEdges = graph.edges;
    sort(sortedEdges.begin(), sortedEdges.end(), compare);

    for (const auto& edge : sortedEdges) {
        int x = findParent(parent, edge.src);
        int y = findParent(parent, edge.dest);

        if (x != y) {
            result.push_back(edge);
            unionSets(parent, x, y);
        }
    }

    for (const auto& edge : result)
        cout << edge.src << " - " << edge.dest << " : " << edge.weight << endl;
}

int main() {
    Graph graph;

    cout << "Enter the number of vertices: ";
    cin >> graph.V;

    cout << "Enter the number of edges: ";
    int numEdges;
    cin >> numEdges;
    graph.edges.resize(numEdges);

    cout << "Enter edge details (source destination weight):" << endl;
    for (int i = 0; i < numEdges; i++)
        cin >> graph.edges[i].src >> graph.edges[i].dest >> graph.edges[i].weight;

    kruskalsMST(graph);

    return 0;
}
*/