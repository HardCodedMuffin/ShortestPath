#include "path.h"

void path::addEdge(vector<vector<param>> *nodecst, int e, int v, int cost)
{
    nodecst->at(e).push_back(make_pair(v, cost));
    nodecst->at(v).push_back(make_pair(e, cost));
}

void path::dijkstra(vector<vector<param>> nodecst, int V, int src)
{
    priority_queue<param, vector <param>, greater<param> > queue;
    vector<int> pathQueue;

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
                pathQueue.push_back(e);
                
                queue.push(make_pair(distance[v], v));
            }
        }
    }

    for (size_t i = 0; i < pathQueue.size(); i++)
    {
        cout << pathQueue.at(i);
    }

    cout << "Vertex \t Distance from Source\n";
    for (int i = 0; i < V; ++i)
        cout << i << "\t " << distance[i] << endl;
}


void path::fileBuffer()
{
    int node;
    file.open("map.txt");
    if (!file) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }

    file >> treeSize >> edge >> cost;
    const int ncs = treeSize;

    //vector<pair<int, int>> nodecst[ncs];

    nodecst.resize(treeSize);

    for (int i = 0; i < treeSize; i++)
    {
        file >> node >> edge >> cost;
        addEdge(&nodecst, node, edge, cost);
    }
    dijkstra(nodecst, treeSize, 4);
}
