#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <time.h>

# define MAX INT_MAX

using namespace std;

const int treeSize = 0;

typedef pair<int, int> param;

class path {
private:
	ifstream file;
	vector<vector<param>> adjacents;
	int treeSize, edge, cost, randomSrc;
public:
	void addEdge(vector<vector<param>> *adjacents, int source, int destination, int cost);
	void dijkstra(vector<vector<param>> adjacents, int V, int destination);
	void fileBuffer(bool io);
	void printPath(vector<int> parent, int destination);
};

