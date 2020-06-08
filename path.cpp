#include "path.h"
#include <limits.h> 
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

ifstream inFile;

path::path() {

    inFile.open("test.txt");
    inFile >> n >> m >> c;

    if (!inFile) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }
}

void path::printSolution(int dist[])
{
    std::cout << "Vertex \t\t Distance from Source\n";
    for (int i = 0; i < V; i++)
        std::cout << i << " \t\t " << dist[i] << std::endl;
}

int path::minDistance(int dist[], bool shortestPath[])
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (shortestPath[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
    }
    return min_index;
}

void path::dijkstra(int graph[V][V], int src, int target)
{
    int dist[V];

    bool shortestPath[V];

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, shortestPath[i] = false;

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {

        int u = minDistance(dist, shortestPath);

        shortestPath[u] = true;

        for (int v = src; v <= target; v++)

            if (!shortestPath[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    printSolution(dist);
}

void path::cukstra() {

    int node1, node2, cost, j = 0;

    for (int i = 0; i < n; i++)
    {
        inFile >> node1 >> node2 >> cost;
        graph[i][j] = node1;
        graph[i][j + 1] = node2;
        graph[i][j + 2] = cost;
    }

    dijkstra(graph, 2, 8);
}
