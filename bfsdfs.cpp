#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

void BFS(const vector<vector<int>>& adjacencylist,vector<bool>&visited,queue<int> q){
    if(q.empty()){
        return;
    }

    int vertex=q.front();
    q.pop();
    cout<<vertex<<" ";

    for(int neighbour:adjacencylist[vertex]){
        if(!visited[neighbour]){
            visited[neighbour]=true;
            q.push(neighbour);
        }
    }
    BFS(adjacencylist,visited,q);

}

void DFS(const vector<vector<int>>& adjacencylist,vector<bool>& visited, stack<int> s){
    if(s.empty()){
        return;
    }

    int vertex=s.top();
    s.pop();
    cout<<vertex<<" ";
    for(int neighbour:adjacencylist[vertex]){
        if(!visited[neighbour]){
            visited[neighbour]=true;
            s.push(neighbour);
        }
    }
    DFS(adjacencylist,visited,s);
}

int main()
{
    int nedges,nvertices;
    cout<<"ENter the number of vertex";
    cin>>nvertices;
    cout<<"Enter the number of edges:";
    cin>>nedges;

    vector<vector<int>> adjacencylist(nvertices);

    cout<<"Enter the edges in (source destination)";
    for(int i=0;i<nedges;i++){
        int u,v;
        cin>>u,v;
        adjacencylist[u].push_back(v);
        adjacencylist[v].push_back(u);
    }

    int startvertex;
    cin>>startvertex;

    cout<<"BfS traversal is: ";
    vector<bool> visitedBFS(nvertices,false);
    queue<int> q;
    visitedBFS[startvertex]=true;
    q.push(startvertex);
    BFS(adjacencylist,visitedBFS,q);

    return 0;

}