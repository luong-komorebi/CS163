// Thanh Luong 1551020
//guide to implement DFS and BFS

#include <iostream>
#include <list>
using namespace std;

class Graph {
	int V;
	list<int> *adj;
public:
	Graph(int V);
	void addEdge(int v, int w);
	void BFS(int source);
};

Graph::Graph(int V) {
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w) {
	adj[v].push_back(w);
}

void Graph::BFS(int source) {
	bool* visited = new bool[V];
	for (int i = 0; i < V; i++) {
		visited[i] = false;
	}

	//this part is the main difference between BFS and DFS
	// We make a queue ( actually it's built on list but queue help us recall the FIFO process )
	list<int> queue;
	visited[source] = true; // mark the vertex we just visited 

	queue.push_back(source);  // push it in the back

	list<int>::iterator i;  // call the iterator out 

	while (!queue.empty()) {

		//basically , we first begin from the source.
		// Add every vertex in the source list inside the queue. then gradually dequeue all of these.
		// Then continue with another list until there are no more list ( the iterator does this for us) 
		source = queue.front();
		cout << source << " ";
		queue.pop_front();
		for (i = adj[source].begin(); i != adj[source].end(); i++) {
			if (visited[*i] == false) {
				visited[*i] = true;
				queue.push_back(*i);
			}
		}

	}
}


int main() {
	int x, vertex1 = 0, vertex2 = 0;
	cout << " Please insert the number of vertices :  ";
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
	cout << " BFS : ";
	graph.BFS(x);
	system("pause");
	return 0;
}