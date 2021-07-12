/* Depth First Search algorithm for a graph
Name: Shivam Verma
Course: B.Sc. (H) Computer Science
Semester: 4th
Roll No.: 19HCS4048
*/

#include <bits/stdc++.h>

using namespace std;

class Graph
{
    map<int, bool> visited;
    map<int, list<int>> adj;

    public:

        void addEdge(int, int);

        void DFS(int);
};

void Graph :: addEdge(int v, int w)
{
    adj[v].push_back(w);
}

void Graph :: DFS(int v)
{
    visited[v] = true;
    cout << v << " ";

    list<int> :: iterator i;

    for(i = adj[v].begin(); i != adj[v].end(); ++i)
        if(!visited[*i])
            DFS(*i);
}

int main()
{
    Graph graph;
    graph.addEdge(0, 1);
    graph.addEdge(0, 9);
    graph.addEdge(1, 2);
    graph.addEdge(2, 0);
    graph.addEdge(2, 3);
    graph.addEdge(9, 3);

    cout << "Depth First Search (from Vertex 2)...\n";
    graph.DFS(2);

    return 0;
}