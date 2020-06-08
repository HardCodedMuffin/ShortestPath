#pragma once

constexpr auto V = 8;

class path
{
public:
    
    int graph[3][8];
    int n, m, c;
    
    path();
    void dijkstra(int graph[V][V], int src, int target);
    void printSolution(int dist[]);
    int minDistance(int dist[], bool shortestPath[]);
    void cukstra();


};

