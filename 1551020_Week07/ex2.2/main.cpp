// Thanh Luong 1551020
//guide to implement DFS and BFS

#include<iostream>
#include<list>

using namespace std;

// let's go!


//first we define the graph class which consist of
// An array of list container for storing our edges 
// Utilities for DFS

class Graph
{
	int V;
	list<int> *adj;
	// here we have a private function to ensure that the program is secure
	// as users cannot manipulate visited[], which we need for recursion.
	void DFSUtil(int v, bool visited[]);
public:
	Graph(int V);
	void addEdge(int v, int w);
	void DFS(int v);
};

Graph::Graph(int V)
{
	//constructor for the graph
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{ // add edge
	adj[v].push_back(w);
}

void Graph::DFSUtil(int v, bool visited[])
{
	// a util to depth first search

	visited[v] = true;  // mark visited vertex
	cout << v << " ";

	list<int>::iterator i;    // loop through the whole array of list. 
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])    // if visited, continue deep down low by using recursion! 
			DFSUtil(*i, visited);
}


void Graph::DFS(int v)
{
	// make a visited to mark visited vertex
	bool *visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;  // initialize all the visited with false since we havent visited any vertex.

	// this is for calling the util
	DFSUtil(v, visited);
}


int main()
{
	int x, vertex1, vertex2;
	cout << " input how many vertices : ";
	cin >> x;
	Graph graph(x);
	do {
		cout << " Input edges ! Input a number < 0 to stop!\n";
		cout << "From vertex : ";
		cin >> vertex1;
		cout << "To vertex : ";
		cin >> vertex2;
		if (vertex1 >= 0 && vertex2 >= 0) { // only choose 1 if this is an directed graph
			graph.addEdge(vertex1, vertex2);// but here i choose to add 2 way because this is undirected graph
			graph.addEdge(vertex2, vertex1);
		}
		else break;
	} while (vertex1 >= 0 && vertex2 >= 0);
	cout << endl;
	cout << "Choose starting point : ";
	cin >> x;
	cout << " DFS : ";
	graph.DFS(x);
	system("pause");
	return 0;
}