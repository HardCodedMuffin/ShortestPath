#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

# define MAX INT_MAX

using namespace std;

const int V = 9;
//int node1, node2, cost;

typedef pair<int, int> iPair;

//ifstream file;

class path {
public:
	void addEdge(vector <pair<int, int> > adj[], int u, int v, int wt);
	void shortestPath(vector<pair<int, int> > adj[], int V, int src);
	void fileBuffer();
};