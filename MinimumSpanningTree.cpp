/* Using any greedy approach find the Minimum Spanning Tree of a graph.
Name: Shivam Verma
Course: B.Sc. (H) Computer Science
Semester: 4th 
Roll No: 19HCS4048
*/

#include <bits/stdc++.h>

using namespace std;

class Edge {
	public: 
		int source;
		int destination;
		int weight;
};

bool compare(Edge e1, Edge e2)
{
	return e1.weight < e2.weight;
}

int findParent(int v, int* parent)
{
	if(parent[v] == v)
		return v;
	return findParent(parent[v], parent);
}

void kruskals(Edge *input, int n, int E) 
{
	sort(input, input + E, compare);  	//Sort the input array in ascending order according to their weight

	Edge *output = new Edge[n-1];
	int *parent = new int[n]; 

	for(int i = 0; i < n; i++)
		parent[i] = i;
	
	int count = 0, i = 0;

	while(count != n-1)
	{
		Edge currentEdge = input[i];
		int sourceParent = findParent(currentEdge.source, parent);  //Check if we can the current edge in MST or not
		int destParent = findParent(currentEdge.destination, parent);
		
		if(sourceParent != destParent)
		{
			output[count] = currentEdge;
			count++;
		}
		parent[sourceParent] = destParent;
		i++;
	}
	
	for(int i = 0; i < n-1; i++)
		if(output[i].source < output[i].destination)
			cout << output[i].source << " " << output[i].destination << " " << output[i].weight << "\n";
		else
			cout << output[i].destination << " " << output[i].source << " " << output[i].weight << "\n";	
}

int main ()
{
	int v, e;

	cout << "Enter the Number of Vertices of the graph \n"; 
	cin >> v;

	cout << "Enter the Number of edges in graph \n";
	cin >> e;

	Edge *input = new Edge[e];
	cout << "\n Enter the source, destination and weight for each edge respectively : \n";

	for(int i = 0; i < e; i++)
	{
		int s, d, w;

		cout << "For Edge " << i + 1 << " : ";
		cin >> s >> d >> w;
		input[i].source = s;
		input[i].destination = d;
		input[i].weight = w;
		cout << "\n";
	}
	kruskals(input, v, e);
 	return 0;
}