#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> graph;
vector<int> color;
// Function to check if it is safe to color a vertex with a given color
bool isSafe(int vertex, int vertexColor) {
    for (int neighbor : graph[vertex]) {
        if (color[neighbor] == vertexColor)
            return false;
    }
    return true;
}
// Recursive function to assign colors to the vertices
bool graphColorUtil(int vertex, int numColors) {
    if (vertex == graph.size())
        return true;

    for (int vertexColor = 1; vertexColor <= numColors; vertexColor++) {
        if (isSafe(vertex, vertexColor)) {
            color[vertex] = vertexColor;
            if (graphColorUtil(vertex + 1, numColors))
                return true;
            color[vertex] = 0; // Backtrack
        }
    }
    return false;
}

// Function to find the minimum number of colors required to color the graph
int graphColoring() {
    int numVertices;
    cout << "Enter the number of vertices in the graph: ";
    cin >> numVertices;
    graph.resize(numVertices);
    cout << "Enter the number of edges in the graph: ";
    int numEdges;
    cin >> numEdges;

    cout << "Enter the edges in the format 'u v' (0-based indexing):" << endl;
    for (int i = 0; i < numEdges; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int maxDegree = 0;
    for (int i = 0; i < numVertices; i++)
        maxDegree = max(maxDegree, static_cast<int>(graph[i].size()));
    for (int numColors = 1; numColors <= maxDegree + 1; numColors++) {
        color.resize(numVertices, 0);
        if (graphColorUtil(0, numColors))
            return numColors;
    }
    return -1; // No solution found
}

int main() {
    int minNumColors = graphColoring();
    if (minNumColors != -1)
        cout << "Minimum number of colors required to color the graph: " << minNumColors << endl;
    else
        cout << "No valid coloring possible for the given graph." << endl;

    return 0;
}
