#include "path.h"

//Function that adds the edge
void path::addEdge(vector<vector<param>>* adjacents, int source, int destination, int cost)
{
    adjacents->at(source).push_back(make_pair(destination, cost));
    adjacents->at(destination).push_back(make_pair(source, cost));
}

//Main algrorithm that calculates the shortest path via Djisktra's alogrithm
void path::dijkstra(vector<vector<param>> adjacents, int treeSize, int destination)
{
    //Initializes priority queue
    priority_queue <param, vector <param>, greater<param> > queue;

    //Our vectors for keeping the distance and visited vertices
    vector<int> distance(treeSize, MAX);
    vector<int> visited(treeSize);

    //Adding the destination as a pair to the queue
    queue.push(make_pair(0, destination));

    //Getting the distance for the destination from the array
    distance[destination] = 0;

    //Starting from the start vertex that is created randomly
    visited.at(0) = randomSrc;

    //Loop continues until the queue gets empty (all elements are popped from the queue)
    while (!queue.empty())
    {
       //Getting the top pair's second element (destination's cost)
        int u = queue.top().second;
        queue.pop(); //Removing from the queue

        //Auto loop that tries for every adjacent node of the destination
        for (auto x : adjacents[u])
        {
            int v = x.first; //sets the next step
            int cost = x.second;  //gets the cost

            //Checks if there is a shorter way to the same target
            if (distance[v] > distance[u] + cost)
            {
                distance[v] = distance[u] + cost; //Adds to the total cost
                queue.push(make_pair(distance[v], v)); //pushes the new pair (distances)
                visited.at(v) = u; // Adds the subject vertex as visited (To be used to print the shortest path at the end)
            }
        }
    }
    outputFile << randomSrc << " "; //Prints the start index to the output file
    if (randomSrc != treeSize - 1) //Exception that checks if the start vertex is also the target vertex
    printPath(visited, visited[randomSrc]);
}


//Recursive code sequence that prints the shorthest path from the visited vector
void path::printPath(vector<int> visited, int destination)
{
    outputFile << destination << " ";
    
    if (visited[destination] == NULL) 
        return;
    

    printPath(visited, visited[destination]);
}

//Code sequence for opening, reading and buffering the input file
void path::fileBuffer()
{
    int node;
    inputFile.open("input.txt");
    outputFile.open("output.txt");
    if (!inputFile && !outputFile) {
        cout << "Unable to open files!";
        exit(1);
    }

    //Parsing way
    inputFile >> treeSize >> edge >> cost;

    //Randomizing the start index
    srand(time(NULL));
    randomSrc = rand() % edge;
    
    const int ncs = treeSize;

    adjacents.resize(treeSize);

    //Adds the edge and vertices till reaching the size of the file
    for (int i = 0; i < treeSize; i++)
    {
        inputFile >> node >> edge >> cost;
        addEdge(&adjacents, node, edge, cost);
    }

    //Calling the calculating algorithm    
    dijkstra(adjacents, treeSize, treeSize - 1);
    
    cout << "Done! Please check \"output.txt\" to see solution";
    
    //Closing the files
    inputFile.close();
    outputFile.close();
}
