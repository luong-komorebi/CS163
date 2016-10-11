//1551020_Week08
// Vo Tran Thanh Luong

#include <iostream>
using namespace std;

//read Main() first, then slowly trace back to other functions.

//This is a tool to find the minimum distance. 
int minDistance(int distance[], bool sptSet[]) {

	int min = INT_MAX; //initial min
	int min_index;   //we need this index for later

	for (int i = 0; i < 9; i++) {

		if (distance[i] <= min && sptSet[i] == false) {    // if distance from source to point i is less than min
														   //  and point i was never in the shortest path set, update min and min index

			min_index = i;
			min = distance[i];
		}
	}
	return min_index;
}

// a function to print out what we have done!
void printout(int distance[]) {
	for (int i = 0; i < 9; i++) {
		cout << " Distance from start vertex to point : " << i << " is " << distance[i] << endl;
	}
}

// implemntation of dikstra algorithm
void dikstra(int graph[9][9], int source) {
	int distance[9];
	bool sptSet[9];

	//first , set all distance to infinity and all spt_set to false ( because no point has been chosen to put in that set yet)
	for (int i = 0; i < 9; i++) {
		distance[i] = INT_MAX;
		sptSet[i] = false;
	}

	//start from the source so distance from source to source = 0;
	distance[source] = 0;

	//this loop only execute 8 times because we dont need the last time (will have alr found out all by then)
	for (int i = 0; i < 8; i++) {
		int index = minDistance(distance, sptSet); //get the index of the smallest distance
		sptSet[index] = true;    //set it to true = put that "point" (marked with a quote to prevent misunderstanding) in shortestpathset

								 // now loop 9 times for 9 points.
		for (int i = 0; i < 9; i++) {

			// if that "point" was not in sptSet +
			// there is a path between that "point" and the current point (no quote mark) in this loop  
			// (actually we are trying to get the adjacent points' distance)
			// and the distance from "point" to the adjacent point is shorter than the distance from source to point
			// update the distance from source to point.
			if (sptSet[i] != true && graph[index][i] != 0 && distance[index] != INT_MAX && distance[index] + graph[index][i] <= distance[i]) {
				distance[i] = distance[index] + graph[index][i];
			}
		}
	}
	printout(distance);

}

//Actually the graph is just a model that represents the distance between two points
int main() {
	int n;
	int graph[9][9] = {
		{ 0, 4, 0, 0, 0, 0, 0, 8, 0 },
		{ 4, 0, 8, 0, 0, 0, 0, 11, 0 },
		{ 0, 8, 0, 7, 0, 4, 0, 0, 2 },
		{ 0, 0, 7, 0, 9, 14, 0, 0, 0 },
		{ 0, 0, 0, 9, 0, 10, 0, 0, 0 },
		{ 0, 0, 4, 0, 10, 0, 2, 0, 0 },
		{ 0, 0, 0, 14, 0, 2, 0, 1, 6 },
		{ 8, 11, 0, 0, 0, 0, 1, 0, 7 },
		{ 0, 0, 2, 0, 0, 0, 6, 7, 0 }
	};
	cout << " Demo 9x9 graph : \n{ 0, 4, 0, 0, 0, 0, 0, 8, 0  },\n{ 4, 0, 8, 0, 0, 0, 0, 11, 0 },\n{ 0, 8, 0, 7, 0, 4, 0, 0, 2  },\n{ 0, 0, 7, 0, 9, 14, 0, 0, 0 },\n{ 0, 0, 0, 9, 0, 10, 0, 0, 0 },\n{ 0, 0, 4, 0, 10, 0, 2, 0, 0 },\n{ 0, 0, 0, 14, 0, 2, 0, 1, 6 },\n{ 8, 11, 0, 0, 0, 0, 1, 0, 7 },\n{ 0, 0, 2, 0, 0, 0, 6, 7, 0  }\n";
	cout << " Choose start vertex : ";
	cin >> n; // take desired input to go dikstra
	while (n < 0 || n > 8) {
		cout << " Please enter a number which is smaller than 8 only :\n";
		cin >> n;
	}
	dikstra(graph, n);
	system("pause");
	return 0;
}