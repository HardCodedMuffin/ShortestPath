#include "path.h"

void path::addEdge(vector<vector<param>>* adjacents, int source, int destination, int cost)
{
    adjacents->at(source).push_back(make_pair(destination, cost));
    adjacents->at(destination).push_back(make_pair(source, cost));
}

void path::dijkstra(vector<vector<param>> adjacents, int treeSize, int destination)
{
    priority_queue <param, vector <param>, greater<param> > queue;

    vector<int> distance(treeSize, MAX);
    vector<int> visited(treeSize);

    queue.push(make_pair(0, destination));

    distance[destination] = 0;
    visited.at(0) = randomSrc;

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
                distance[v] = distance[u] + cost;
                queue.push(make_pair(distance[v], v));
                visited.at(v) = u;
            }
        }
    }
    outputFile << randomSrc << " ";
    if (randomSrc != treeSize - 1)
    printPath(visited, visited[randomSrc]);
}


void path::printPath(vector<int> visited, int destination)
{
    outputFile << destination << " ";
    
    if (visited[destination] == NULL) 
        return;
    

    printPath(visited, visited[destination]);
}

void path::fileBuffer()
{
    int node;
    inputFile.open("input.txt");
    outputFile.open("output.txt");
    if (!inputFile && !outputFile) {
        cout << "Unable to open files!";
        exit(1);
    }

    inputFile >> treeSize >> edge >> cost;

    srand(time(NULL));
    //randomSrc = rand() % edge;
    randomSrc = 7;
    const int ncs = treeSize;

    adjacents.resize(treeSize);

    for (int i = 0; i < treeSize; i++)
    {
        inputFile >> node >> edge >> cost;
        addEdge(&adjacents, node, edge, cost);
    }
    
    dijkstra(adjacents, treeSize, treeSize - 1);
    
    cout << "Done! Please check \"output.txt\" to see solution";
    
    inputFile.close();
    outputFile.close();
}
