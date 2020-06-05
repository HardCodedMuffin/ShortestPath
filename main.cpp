#include <limits.h> 
#include <iostream>


#define V 9 

void printSolution(int dist[])
{
    std::cout << "Vertex \t\t Distance from Source\n";
    for (int i = 0; i < V; i++)
        std::cout << i << " \t\t " << dist[i] << std::endl;
}

int minDistance(int dist[], bool shortestPath[])
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (shortestPath[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
    }
        printSolution(dist);
    return min_index;
}


void dijkstra(int graph[V][V], int src, int target)
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

int main()
{
    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

    dijkstra(graph, 1, 4);

    return 0;
}