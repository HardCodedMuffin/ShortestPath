#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

# define MAX INT_MAX

using namespace std;

const int V = 9;

typedef pair<int, int> param;

class path {
private:
	ifstream file;
	vector<vector<param>> nodecst;
	int node, edge, cost;
public:
	void fileBuffer();
	void addEdge(vector<vector<param>> adj, int u, int v, int wt);
	void dijkstra(vector<vector<param>> adj, int V, int src);
};

