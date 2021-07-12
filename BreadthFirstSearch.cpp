/* Breadth Search First algorithm for a graph
Name: Shivam Verma
Course: B.Sc.(H) Computer Science 4th semester
Roll No.: 19HCS4048
*/

#include <bits/stdc++.h>

using namespace std;

class Graph
{
    int vertices;
    list<int> *adjacency;

    public:

        Graph(int vertices)
        {
            this->vertices = vertices;
            adjacency = new list<int>[vertices];
        }

        void addEdge(int, int);

        void BFS(int);
};

void Graph :: addEdge(int vertex, int element) 
{
    adjacency[vertex].push_back(element);
}

void Graph :: BFS(int source)
{
    bool *visited = new bool[vertices];
    for(int index = 0; index < vertices; ++index)
        visited[index] = false;

    list<int> queue;
    
    visited[source] = true;
    queue.push_back(source);

    list<int> :: iterator i;

    while(!queue.empty())
    {
        source = queue.front();
        cout << source << "  ";
        queue.pop_front();

        for(i = adjacency[source].begin(); i != adjacency[source].end(); ++i)
            if(!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
    }
}

int main()
{
    Graph graph(4);

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 2);
    graph.addEdge(2, 0);
    graph.addEdge(2, 3);
    graph.addEdge(3, 3);

    cout << "Breadth First Search (from Vertex 2)...\n";
    graph.BFS(2);

    return 0;
}