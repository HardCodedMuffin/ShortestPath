#include "path.h"



void path::addEdge(vector<vector<param>> nodecst, int e, int v, int cost)
{
    nodecst[e].push_back(make_pair(v, cost));
    nodecst[v].push_back(make_pair(e, cost));

}

void path::dijkstra(vector<vector<param>> nodecst, int V, int src)
{
    priority_queue< param, vector <param>, greater<param> > queue;

    vector<int> distance(V, MAX);

    queue.push(make_pair(0, src));
    distance[src] = 0;

    while (!queue.empty())
    {
        int e = queue.top().second;
        queue.pop();

        for (auto x : nodecst[e])
        {
            int v = x.first;
            int cost = x.second;

            if (distance[v] > distance[e] + cost)

            {
                distance[v] = distance[e] + cost;
                queue.push(make_pair(distance[v], v));
            }
        }
    }

    cout << "Vertex \t Distance from Source\n";
    for (int i = 0; i < V; ++i)
        cout << i << "\t " << distance[i] << endl;
}


void path::fileBuffer()
{
    file.open("map.txt");
    if (!file) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }
    file >> node >> edge >> cost;
    const int ncs = node;
    //vector<pair<int, int>> nodecst[ncs];

    for (int i = 0; i < V; i++)
    {
        file >> node >> edge >> cost;
        addEdge(nodecst, node, edge, cost);
    }
    dijkstra(nodecst, V, 0);
}
