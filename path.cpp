#include "path.h"

void path::addEdge(vector<vector<param>> *adjacents, int source, int destination, int cost)
{
    adjacents->at(source).push_back(make_pair(destination, cost));
    adjacents->at(destination).push_back(make_pair(source, cost));
}

void path::dijkstra(vector<vector<param>> adjacents, int treeSize, int src)
{
    priority_queue <param, vector <param>, greater<param> > queue;

    vector<int> distance(treeSize, MAX);
    vector<int> parent;

    queue.push(make_pair(0, src));

    distance[src] = 0;
    //parent.clear();

    while (!queue.empty())
    {
        int u = queue.top().second;
        queue.pop();

        for (auto x : adjacents[u])
        {
            int v = x.first;
            int cost = x.second;

            if (distance[v] > distance[u] + cost)
            {
                //parent.push_back(v);
                distance[v] = distance[u] + cost;
                queue.push(make_pair(distance[v], v));
            }
        }
    }

    cout << "Vertex \t Distance from Source\n";
    for (int i = 0; i < treeSize; ++i) {
        cout << i << "\t " << distance[i] << endl;
        //printPath(parent, parent[j]);
    }
}

//To DO
//void path::printPath(int parent[], int j)
//{
//    if (parent[j] == -1)
//        return;
//
//    printPath(parent, parent[j]);
//
//    cout << j;
//}


void path::fileBuffer()
{
    int node;
    file.open("input.txt");
    if (!file) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }

    file >> treeSize >> edge >> cost;
    const int ncs = treeSize;

    nodecst.resize(treeSize);

    for (int i = 0; i < treeSize; i++)
    {
        file >> node >> edge >> cost;
        addEdge(&nodecst, node, edge, cost);
    }
    srand(time(NULL));
    randomSrc = rand() % edge;
    dijkstra(nodecst, treeSize, randomSrc);
}
